#include "cpu_info.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Constructor calls the helper function to fetch data immediately
CPUInfo::CPUInfo() {
    cores = 0;
    modelName = "Unknown";
    fetchCPUData();
}

// Function to read /proc/cpuinfo and extract model name and cores
void CPUInfo::fetchCPUData() {
    // In Linux, /proc/cpuinfo contains information about the CPU.
    // We use a file stream to read this pseudo-file.
    ifstream cpuFile("/proc/cpuinfo");
    
    if (!cpuFile.is_open()) {
        cout << "Error: Could not open /proc/cpuinfo. (Are you running this on Windows?)" << endl;
        return;
    }

    string line;
    // Read the file line by line
    while (getline(cpuFile, line)) {
        // Look for the "model name" line
        if (line.find("model name") == 0) {
            // Find the colon and extract the substring after it
            size_t colonPos = line.find(":");
            if (colonPos != string::npos) {
                // We do this only once so we don't overwrite with every core's model name
                if (modelName == "Unknown") {
                    // +2 to skip the colon and the space after it
                    modelName = line.substr(colonPos + 2); 
                }
            }
        }
        // Look for the "processor" line to count the number of cores
        else if (line.find("processor") == 0) {
            cores++; // Every time we see "processor", it means an additional core
        }
    }
    
    cpuFile.close();
}

// Public function to display the collected data
void CPUInfo::printCPUDetails() {
    cout << "\n--- CPU Information ---" << endl;
    cout << "CPU Model : " << modelName << endl;
    cout << "CPU Cores : " << cores << endl;
    cout << "-----------------------" << endl;
}
