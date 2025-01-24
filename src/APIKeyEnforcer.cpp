/* 
 *    ___         __  ____                   
 *   / __/_ ____ / /_/ / /_ _   _______  ___    C++ for Fast LLM Inference
 *  / _/ _ `(_-</ __/ / /  ' \_/ __/ _ \/ _ \   version 0.0.1
 * /_/ \_,_/___/\__/_/_/_/_/_(_)__/ .__/ .__/   https://github.com/thansen0
 *                               /_/  /_/    
 *
 * SPDX-FileCopyrightText: 2025 thansen0 <https://github.com/thansen0>
 * SPDX-License-Identifier: Unlicense
 */

#include <vector>
#include <algorithm> // contains find function
#include <cstring> // strlen
#include <curl/curl.h>
#include "APIKeyEnforcer.h"
#include <iostream>
#include <chrono>
#include <jansson.h>

using namespace std;


/************** Simple Verification ***************/

APIKeyEnforcer::APIKeyEnforcer(vector<string> key_list)
    : key_list(key_list)
{
}

APIKeyEnforcer::~APIKeyEnforcer() {}

bool APIKeyEnforcer::KeyVerify(string unique_key) {

    return find(key_list.begin(), key_list.end(), unique_key) != key_list.end();
}

std::vector<std::string> APIKeyEnforcer::ReturnKeys() {
    return key_list;
}


/***************** Token Bucket *******************/

uint64_t getCurrentTimeNanoseconds() {
    auto now = std::chrono::high_resolution_clock::now();
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
    return static_cast<uint64_t>(ns);
}

inline TokenBucket::TokenBucket(uint64_t rate, uint64_t burst)
    : _time(0),
      _time_per_token(1000000000 / rate),
      _time_per_burst(burst * _time_per_token)
{
}

inline TokenBucket::TokenBucket(const TokenBucket& tb)
    : _time(tb._time.load()),
      _time_per_token(tb._time_per_token.load()),
      _time_per_burst(tb._time_per_burst.load())
{
}

inline TokenBucket& TokenBucket::operator=(const TokenBucket& tb) {
    _time = tb._time.load();
    _time_per_token = tb._time_per_token.load();
    _time_per_burst = tb._time_per_burst.load();
    return *this;
}

bool TokenBucket::Consume(uint64_t tokens) {
    uint64_t now = getCurrentTimeNanoseconds();
    uint64_t delay = tokens * _time_per_token.load(std::memory_order_relaxed);
    uint64_t minTime = now - _time_per_burst.load(std::memory_order_relaxed);
    uint64_t oldTime = _time.load(std::memory_order_relaxed);
    uint64_t newTime = oldTime;

    // shift new time to the start of a new burst
    if (minTime > oldTime)
        newTime = minTime;

    // token consumption loop
    for (;;)
    {
        // consume tokens
        newTime += delay;

        // no more tokens left in the bucket
        if (newTime > now)
            return false;

        // try to update the current time atomically
        if (_time.compare_exchange_weak(oldTime, newTime, std::memory_order_relaxed, std::memory_order_relaxed))
            return true;

        // failed, retry consume tokens with a new time value
        newTime = oldTime;
    }
}




APIKeyEnforcerTB::APIKeyEnforcerTB(vector<string> key_list, const int rate, const int burst) {
    this->rate = rate;
    this->burst = burst;

    // build hash map of Token Buckets
    for (std::string key : key_list) {
        this->key_list.insert({key, new TokenBucket(rate, burst)});
    }
}

APIKeyEnforcerTB::~APIKeyEnforcerTB() {
    for (auto& hash_items : key_list) {
        delete hash_items.second;
    }
    key_list.clear();
}

bool APIKeyEnforcerTB::KeyVerify(string unique_key) {
    if (key_list.find(unique_key) == key_list.end()) {
        return false;
    }

    key_list[unique_key]->Consume();
    return true;
}

void APIKeyEnforcerTB::AddKey(string unique_key) {
    this->key_list.insert({unique_key, new TokenBucket(this->rate, this->burst)});
}

std::vector<std::string> APIKeyEnforcerTB::ReturnKeys() {
    // move from unordered map to vector
    vector<string> keys(key_list.size());

    int key_index = 0;
    for (auto kv : key_list) {
        keys[key_index++] = kv.first;
    }

    return keys;
}



/************ TB with API User Add ****************/
// static helper function
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    // size * nmemb is the actual size of the data
    size_t totalSize = size * nmemb;
    // append the received chunk to our response string
    ((std::string*)userp)->append((char*)contents, totalSize);
    return totalSize;
}


APIKeyEnforcerTBAddUser::APIKeyEnforcerTBAddUser(vector<string> key_list, const std::string url, const int rate, const int burst) : rate(rate), burst(burst), verify_url(url) {
//    this->rate = rate;
//    this->burst = burst;

    // build hash map of Token Buckets
    for (std::string key : key_list) {
        this->key_list.insert({key, new TokenBucket(rate, burst)});
    }
}

APIKeyEnforcerTBAddUser::~APIKeyEnforcerTBAddUser() {
    for (auto& hash_items : key_list) {
        delete hash_items.second;
    }
    key_list.clear();
}

std::string APIKeyEnforcerTBAddUser::POSTtoAPI(const char* json_str) {
    std::string responseBuffer;

    // leave if error and no data
    if (strlen(json_str) < 1) {
        return "";
    }

    // CURL* cannot be shared between threads
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return "";
    }

    // set HTTP headers and body/attributes
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_URL, this->verify_url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (curl_off_t)strlen(json_str));

    // captures server response
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

    // perform blocking request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "LLM Request Recording/Logging failed: "
                  << curl_easy_strerror(res) << std::endl;
        // records error, still returns error string
    } else {
        // Successfully received a response.
        // Print it out (or parse with a JSON library if desired).
        std::cout << "Server response:\n" << responseBuffer << std::endl;
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    return responseBuffer;
}

bool APIKeyEnforcerTBAddUser::KeyVerify(string unique_key) {
    if (key_list.find(unique_key) == key_list.end()) {
        // must contact remote server to check whether key exists
        // build json api
        json_t *root = json_object();
        if(!root) {
            std::cerr << "Failed to create 'root' object." << std::endl;
            return false;
        }

        // populate json request data fields
        json_object_set_new(root, "key", json_string(unique_key.c_str()));

        char *json_str = json_dumps(root, JSON_INDENT(0));
        if(!json_str) {
            std::cerr << "Failed to serialize JSON object." << std::endl;
            json_decref(root);
            return false;
        }
        std::cout << " APIKeyEnforcerTBAddUser json_str created:\n" << json_str << "\nsize: " << strlen(json_str) << std::endl;

        try {
            // send post request using libcurl
            std::string contKey = this->POSTtoAPI(json_str);
            // TODO break down json, don't just use find
            if (contKey.find(unique_key) == std::string::npos) {
                return false;
            } else {
                return true;
            }

        } catch (const std::exception& e) {
            std::cerr << "Exception occurred: " << e.what() << std::endl;
        }


        // clean up
        free(json_str);
        json_decref(root);

        return false;
    }

    key_list[unique_key]->Consume();
    return true;
}

void APIKeyEnforcerTBAddUser::AddKey(string unique_key) {
    this->key_list.insert({unique_key, new TokenBucket(this->rate, this->burst)});
}

std::vector<std::string> APIKeyEnforcerTBAddUser::ReturnKeys() {
    // move from unordered map to vector
    vector<string> keys(key_list.size());

    int key_index = 0;
    for (auto kv : key_list) {
        keys[key_index++] = kv.first;
    }

    return keys;
}


