#include "system_info.h"
#include <iostream>
#include <fstream>

using namespace std;

SystemInfo::SystemInfo() {
    uptimeSeconds = 0;
    hours = 0;
    minutes = 0;
    seconds = 0;
    fetchUptimeData();
}

void SystemInfo::fetchUptimeData() {
    // /proc/uptime contains two values:
    // 1. Uptime of the system in seconds
    // 2. Amount of time spent in idle process in seconds
    ifstream uptimeFile("/proc/uptime");
    
    if (!uptimeFile.is_open()) {
        cout << "Error: Could not open /proc/uptime. (Are you running this on Windows?)" << endl;
        return;
    }

    // We only need the first value
    if (uptimeFile >> uptimeSeconds) {
        // Convert total seconds to hours, minutes, and seconds
        long totalSecs = static_cast<long>(uptimeSeconds);
        hours = totalSecs / 3600;
        minutes = (totalSecs % 3600) / 60;
        seconds = totalSecs % 60;
    }
    
    uptimeFile.close();
}

void SystemInfo::printSystemUptime() {
    cout << "\n--- System Uptime ---" << endl;
    cout << "Uptime : " << hours << " Hours, " 
         << minutes << " Minutes, " 
         << seconds << " Seconds." << endl;
    cout << "---------------------" << endl;
}
