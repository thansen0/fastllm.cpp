#include <stdio.h>
#include <cstring>
#include <iostream>
#include "RecordRequests.h"
#include <curl/curl.h>
#include <jansson.h>

/**************** File Write Implementation *****************/

RecordRequests::RecordRequests(const std::string& filePath) {
    logFile.open(filePath);
    if (!logFile.is_open()) {
        throw std::ios_base::failure("Failed to open log file.");
    }
}

RecordRequests::~RecordRequests() {
    if (logFile.is_open()) {
        printf("CLOSING logfile");
        logFile.close();
    }
}

void RecordRequests::recordLLMRequest(const std::string& prompt_query, const std::string& result, const std::string& user_uuid) {
    if (logFile.is_open()) {
        logFile << "\"" << prompt_query << "\",\"" << result << "," << user_uuid << "\"\n";
        logFile.flush();
    } else {
        std::cerr << "Log file is not open for writing.\n";
    }
}


/*************** API DB Save Implementation *****************/

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    // size * nmemb is the actual size of the data
    size_t totalSize = size * nmemb;
    // append the received chunk to our response string
    ((std::string*)userp)->append((char*)contents, totalSize);
    return totalSize;
}


RecordRequestsREST::RecordRequestsREST(const std::string url) {
    this->record_url = url;
}

RecordRequestsREST::~RecordRequestsREST() {
}

void RecordRequestsREST::POSTtoAPI(const char* json_str) {
    std::string responseBuffer;

    // leave if error and no data
    if (strlen(json_str) < 1) {
        return;
    }

    // CURL* cannot be shared between threads
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return;
    }

    // set HTTP headers and body/attributes
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_URL, this->record_url.c_str());
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
    } else {
        // Successfully received a response.
        // Print it out (or parse with a JSON library if desired).
        std::cout << "Server response:\n" << responseBuffer << std::endl;
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
}


/* 
 * Great example of this here
 * https://github.com/gadamc/examples/blob/master/jansson/sendJsonWithLibcurl.c
 */
void RecordRequestsREST::recordLLMRequest(const std::string& prompt_query, const std::string& result, const std::string& pkey_uuid) {
    // build json request structure
    json_t *root = json_object();
    json_t *prompt = json_object();
    if(!prompt) {
        std::cerr << "Failed to create 'prompt' object." << std::endl;
        json_decref(root);
        return;
    }

    // populate json request data fields
    json_object_set_new(prompt, "prompt", json_string(prompt_query.c_str()));
    json_object_set_new(prompt, "response", json_string(result.c_str()));
    json_object_set_new(prompt, "api_key_key", json_string(pkey_uuid.c_str()));

    // Add the nested object to the root object
    if(json_object_set_new(root, "prompt", prompt) != 0) {
        std::cerr << "Failed to add 'prompt' to JSON object." << std::endl;
        json_decref(prompt);
        json_decref(root);
        return;
    }

    char *json_str = json_dumps(root, JSON_INDENT(0));
    if(!json_str) {
        std::cerr << "Failed to serialize JSON object." << std::endl;
        json_decref(root);
        return;
    }
    std::cout << "json_str created:\n" << json_str << "\nsize: " << strlen(json_str) << std::endl;

    try {
        // send post request using libcurl
        this->POSTtoAPI(json_str);

    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }


    // clean up
    free(json_str);
    json_decref(prompt);
    json_decref(root); // should also free prompt but not clear in docs

}

