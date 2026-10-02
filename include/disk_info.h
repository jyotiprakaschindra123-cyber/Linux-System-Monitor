#ifndef DISK_INFO_H
#define DISK_INFO_H

// The DiskInfo class is responsible for fetching and displaying Disk space statistics
class DiskInfo {
public:
    DiskInfo();
    void printDiskDetails();

private:
    long long totalSpace;     // In Bytes
    long long availableSpace; // In Bytes
    long long usedSpace;      // In Bytes

    void fetchDiskData();
};

#endif // DISK_INFO_H
