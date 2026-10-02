#ifndef PROCESS_INFO_H
#define PROCESS_INFO_H

#include <vector>
#include <string>

// A simple struct to hold basic process details
struct Process {
    int pid;
    std::string name;
};

// The ProcessInfo class reads the /proc directory to find running processes
class ProcessInfo {
public:
    ProcessInfo();
    void printProcessDetails();

private:
    int totalProcesses;
    std::vector<Process> processList;

    void fetchProcessData();
};

#endif // PROCESS_INFO_H
