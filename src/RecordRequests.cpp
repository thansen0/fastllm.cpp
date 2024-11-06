#include <stdio.h>
#include <fstream>
#include <iostream>
#include "RecordRequests.h"

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

void RecordRequests::recordLLMRequest(const std::string& prompt, const std::string& result, const std::string& user_uuid) {
    if (logFile.is_open()) {
        logFile << "\"" << prompt << "\",\"" << result << "," << user_uuid << "\"\n";
        logFile.flush();
    } else {
        std::cerr << "Log file is not open for writing.\n";
    }
}
