#ifndef RECORDREQUESTS_H
#define RECORDREQUESTS_H

#include <fstream>

class RecordRequestsBase {
public:
    virtual ~RecordRequestsBase() = default;

    virtual void recordLLMRequest(const std::string& prompt, const std::string& result, const std::string& user_uuid) = 0;
};



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


class RecordRequestsREST : public RecordRequestsBase {
private:
    std::string record_url;

public:
    RecordRequestsREST(const std::string url);
    virtual ~RecordRequestsREST() override;

    virtual void recordLLMRequest(const std::string& prompt, const std::string& result, const std::string& pkey_uuid) override;
};

#endif // RECORDREQUESTS_H
