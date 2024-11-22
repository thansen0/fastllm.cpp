#ifndef APIKEYENFORCER_H
#define APIKEYENFORCER_H

#include <vector>
#include <string>

class APIKeyEnforcer {
private:
    std::vector<std::string> key_list;

public:
    APIKeyEnforcer();
    ~APIKeyEnforcer();

    bool KeyVerify();

};


#endif // APIKEYENFORCER_H
