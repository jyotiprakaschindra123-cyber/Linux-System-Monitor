#include "memory_info.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

MemoryInfo::MemoryInfo() {
    totalMemory = 0;
    availableMemory = 0;
    usedMemory = 0;
    fetchMemoryData();
}

void MemoryInfo::fetchMemoryData() {
    // /proc/meminfo contains system memory statistics
    ifstream memFile("/proc/meminfo");
    
    if (!memFile.is_open()) {
        cout << "Error: Could not open /proc/meminfo. (Are you running this on Windows?)" << endl;
        return;
    }

    string key;
    long long value;
    string unit;

    // Read the file word by word
    while (memFile >> key >> value >> unit) {
        if (key == "MemTotal:") {
            totalMemory = value;
        } else if (key == "MemAvailable:") {
            availableMemory = value;
        }
    }
    memFile.close();

    // Calculate used memory
    // (Note: This is a basic calculation. Real Linux tools like 'free' use a more complex formula, 
    // but this is sufficient for a beginner-friendly project).
    if (totalMemory > 0) {
        usedMemory = totalMemory - availableMemory;
    }
}

void MemoryInfo::printMemoryDetails() {
    cout << "\n--- Memory Information ---" << endl;
    // Displaying in Megabytes for easier readability
    cout << "Total Memory     : " << totalMemory / 1024 << " MB" << endl;
    cout << "Used Memory      : " << usedMemory / 1024 << " MB" << endl;
    cout << "Available Memory : " << availableMemory / 1024 << " MB" << endl;
    cout << "--------------------------" << endl;
}
