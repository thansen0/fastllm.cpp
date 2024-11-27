#include <vector>
#include <algorithm> // contains find function
#include <string>
#include "APIKeyEnforcer.h"
#include <iostream>
#include <chrono>

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
