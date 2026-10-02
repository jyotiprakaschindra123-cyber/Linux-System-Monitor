#include "disk_info.h"
#include <iostream>
#include <sys/statvfs.h> // POSIX standard API for file system statistics

using namespace std;

DiskInfo::DiskInfo() {
    totalSpace = 0;
    availableSpace = 0;
    usedSpace = 0;
    fetchDiskData();
}

void DiskInfo::fetchDiskData() {
    // statvfs is a struct provided by Linux to hold file system statistics
    struct statvfs stat;

    // We call the statvfs() system function on the root directory "/"
    // If it returns 0, it was successful.
    if (statvfs("/", &stat) != 0) {
        cout << "Error: Could not retrieve disk information. (Are you running this on Windows?)" << endl;
        return;
    }

    // Calculations based on the statvfs structure fields
    // f_blocks: Total data blocks in file system
    // f_frsize: Fragment size (essentially the block size in bytes)
    // f_bavail: Free blocks available to non-privileged users
    
    totalSpace = stat.f_blocks * stat.f_frsize;
    availableSpace = stat.f_bavail * stat.f_frsize;
    
    if (totalSpace > 0) {
        usedSpace = totalSpace - availableSpace;
    }
}

void DiskInfo::printDiskDetails() {
    cout << "\n--- Disk Information (Root Partition /) ---" << endl;
    
    // 1024 * 1024 * 1024 = 1073741824 bytes in a Gigabyte (GB)
    const long long GB = 1073741824;
    
    if (totalSpace > 0) {
        cout << "Total Disk Space     : " << totalSpace / GB << " GB" << endl;
        cout << "Used Disk Space      : " << usedSpace / GB << " GB" << endl;
        cout << "Available Disk Space : " << availableSpace / GB << " GB" << endl;
    } else {
        cout << "Disk information unavailable." << endl;
    }
    cout << "-------------------------------------------" << endl;
}
