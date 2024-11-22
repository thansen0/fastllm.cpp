#ifndef RECORDREQUESTS_H
#define RECORDREQUESTS_H

#include <fstream>

class RecordRequests {
private:
    std::ofstream logFile;

public:
    RecordRequests(const std::string& filePath);

    ~RecordRequests();

    void recordLLMRequest(const std::string& prompt, const std::string& result, const std::string& user_uuid);
};


#endif // RECORDREQUESTS_H
