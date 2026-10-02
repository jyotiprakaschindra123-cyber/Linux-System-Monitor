#include "process_info.h"
#include <iostream>
#include <fstream>
#include <dirent.h> // POSIX directory reading
#include <cctype>   // for isdigit

using namespace std;

ProcessInfo::ProcessInfo() {
    totalProcesses = 0;
    fetchProcessData();
}

// Helper function to check if a string contains only digits
bool isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return !str.empty();
}

void ProcessInfo::fetchProcessData() {
    DIR* procDir = opendir("/proc");
    
    if (procDir == nullptr) {
        cout << "Error: Could not open /proc directory." << endl;
        return;
    }

    struct dirent* entry;
    
    // Read the directory contents one by one
    while ((entry = readdir(procDir)) != nullptr) {
        string dirName = entry->d_name;

        // If the directory name is purely numeric, it is a Process ID (PID)
        if (isNumeric(dirName)) {
            totalProcesses++;
            
            // To keep the display clean, we only store the first 10 processes as a sample
            if (processList.size() < 10) {
                Process p;
                p.pid = stoi(dirName);
                
                // Read the command name from /proc/[pid]/comm
                string commPath = "/proc/" + dirName + "/comm";
                ifstream commFile(commPath);
                if (commFile.is_open()) {
                    getline(commFile, p.name);
                    commFile.close();
                } else {
                    p.name = "Unknown";
                }
                
                processList.push_back(p);
            }
        }
    }
    
    closedir(procDir);
}

void ProcessInfo::printProcessDetails() {
    cout << "\n--- Process Information ---" << endl;
    cout << "Total Running Processes: " << totalProcesses << endl;
    cout << "\nSample of Active Processes:" << endl;
    cout << "PID\tName" << endl;
    cout << "---------------------------" << endl;
    
    for (const auto& p : processList) {
        cout << p.pid << "\t" << p.name << endl;
    }
    
    if (totalProcesses > 10) {
        cout << "... and " << (totalProcesses - 10) << " more." << endl;
    }
    cout << "---------------------------" << endl;
}
