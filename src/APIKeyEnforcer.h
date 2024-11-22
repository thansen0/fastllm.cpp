#ifndef APIKEYENFORCER_H
#define APIKEYENFORCER_H

#include <vector>
#include <string>

class APIKeyEnforcer {
private:
    std::vector<std::string> key_list;

public:
    APIKeyEnforcer(std::vector<std::string> key_list);
    ~APIKeyEnforcer();

    bool KeyVerify(std::string unique_key);

};


#endif // APIKEYENFORCER_H
