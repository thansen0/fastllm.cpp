#include <vector>
#include <algorithm> // contains find function
#include <string>
#include "APIKeyEnforcer.h"

#include <iostream>

using namespace std;

APIKeyEnforcer::APIKeyEnforcer(vector<string> key_list) {
    // TODO assign key_list variables
    this->key_list = key_list;
}

APIKeyEnforcer::~APIKeyEnforcer() {}

bool APIKeyEnforcer::KeyVerify(string unique_key) {

    return find(key_list.begin(), key_list.end(), unique_key) != key_list.end();
}
