#ifndef RECORDREQUESTS_H
#define RECORDREQUESTS_H

#include <fstream>


/**************** Base Class Implementation *****************/

class RecordRequestsBase {
public:
    virtual ~RecordRequestsBase() = default;

    virtual void recordLLMRequest(const std::string& prompt, const std::string& result, const std::string& user_uuid) = 0;
};

/**************** File Write Implementation *****************/

class RecordRequests : public RecordRequestsBase {
private:
    std::ofstream logFile;

public:
    RecordRequests(const std::string& filePath);
    virtual ~RecordRequests() override;

    virtual void recordLLMRequest(const std::string& prompt, const std::string& result, const std::string& pkey_uuid) override;
};


class RecordRequestsNoRecord : public RecordRequestsBase {
public:
    virtual void recordLLMRequest(const std::string& prompt, const std::string& result, const std::string& pkey_uuid) {
        // Doesn't record information
        return;
    }
};


/*************** API DB Save Implementation *****************/

// can't make this function a method without using the userp variable
// since it must be a static extern function 
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

class RecordRequestsREST : public RecordRequestsBase {
private:
    std::string record_url;

    virtual void POSTtoAPI(const char* json_str);

public:
    RecordRequestsREST(const std::string url);
    virtual ~RecordRequestsREST() override;

    virtual void recordLLMRequest(const std::string& prompt, const std::string& result, const std::string& pkey_uuid) override;
};

#endif // RECORDREQUESTS_H
