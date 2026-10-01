#ifndef CPU_INFO_H
#define CPU_INFO_H

#include <string>

// The CPUInfo class is responsible for fetching and displaying CPU details
class CPUInfo {
public:
    // Constructor
    CPUInfo();

    // Main function to print CPU information to the screen
    void printCPUDetails();

private:
    std::string modelName;
    int cores;
    
    // Helper function to read data from /proc/cpuinfo
    void fetchCPUData();
};

#endif // CPU_INFO_H
