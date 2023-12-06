#pragma once

#include <iostream>
#include <fstream>
#include <map>

class AuditLogger {
public:
    AuditLogger(int processID);

    void recordSyscall(unsigned long long callCode);
    void recordEvent(const char* eventData);

    ~AuditLogger();

private:
    static std::map<unsigned long long, std::string> syscallDictionary;

    std::ofstream logFile;
    int targetProcessID;

    std::string getCurrentTime();
};

