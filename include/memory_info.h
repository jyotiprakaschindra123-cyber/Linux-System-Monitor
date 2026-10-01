#ifndef MEMORY_INFO_H
#define MEMORY_INFO_H

// The MemoryInfo class fetches and displays RAM usage statistics
class MemoryInfo {
public:
    MemoryInfo();
    void printMemoryDetails();

private:
    long long totalMemory;     // In Kilobytes
    long long availableMemory; // In Kilobytes
    long long usedMemory;      // In Kilobytes

    void fetchMemoryData();
};

#endif // MEMORY_INFO_H
