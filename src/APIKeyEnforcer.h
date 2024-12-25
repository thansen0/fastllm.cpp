#ifndef APIKEYENFORCER_H
#define APIKEYENFORCER_H

#include <unordered_map>
#include <stdexcept>
#include <vector>
#include <string>

#include <atomic>
#include <cstdint>

using namespace std;

/**************** Base Class Implementation *****************/

class APIKeyEnforcerBase {
public:
    virtual ~APIKeyEnforcerBase() = default;

    virtual bool KeyVerify(std::string unique_key) = 0;
    virtual std::vector<std::string> ReturnKeys() = 0;
    virtual void AddKey(std::string unique_key) {
        throw std::logic_error("AddKey not implemented");
    }
};



/**************** Key Verify Implementation *****************/

class APIKeyEnforcer : public APIKeyEnforcerBase {
private:
    std::vector<std::string> key_list;

public:
    APIKeyEnforcer(std::vector<std::string> key_list);
    ~APIKeyEnforcer();

    bool KeyVerify(std::string unique_key);
    std::vector<std::string> ReturnKeys();
};



/*************** Token Bucket Implementation ****************/

/* 
 * rate - Rate of tokens per second to accumulate in the token bucket
 * burst - Maximum of burst tokens in the token bucket
 */
class TokenBucket
{
public:
    TokenBucket(uint64_t rate, uint64_t burst);
    TokenBucket(const TokenBucket& tb);
    TokenBucket(TokenBucket&&) = delete;
    ~TokenBucket() = default;

    TokenBucket& operator=(const TokenBucket& tb);
    TokenBucket& operator=(TokenBucket&&) = delete;

    bool Consume(uint64_t tokens = 1);

private:
    std::atomic<uint64_t> _time;
    std::atomic<uint64_t> _time_per_token;
    std::atomic<uint64_t> _time_per_burst;
};

class APIKeyEnforcerTB : public APIKeyEnforcerBase {
private:
    std::unordered_map<string, TokenBucket*> key_list;
    int rate;
    int burst;

public:
    APIKeyEnforcerTB(std::vector<std::string> key_list, const int rate=10, const int burst=10);
    ~APIKeyEnforcerTB();

    bool KeyVerify(std::string unique_key);
    void AddKey(std::string unique_key);
    std::vector<std::string> ReturnKeys();
};

/************ TB with API User Add ****************/
// uses TokenBucket implementation above

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

class APIKeyEnforcerTBAddUser : public APIKeyEnforcerBase {
private:
    std::unordered_map<string, TokenBucket*> key_list;
    const std::string verify_url;
    int rate;
    int burst;

    virtual std::string POSTtoAPI(const char* json_str);

public:
    APIKeyEnforcerTBAddUser(std::vector<std::string> key_list, const std::string url, const int rate=10, const int burst=10);
    ~APIKeyEnforcerTBAddUser();

    bool KeyVerify(std::string unique_key);
    void AddKey(std::string unique_key);
    std::vector<std::string> ReturnKeys();
};


#endif // APIKEYENFORCER_H
