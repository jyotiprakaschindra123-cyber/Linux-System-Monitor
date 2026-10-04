#include "report_generator.h"
#include "cpu_info.h"
#include "memory_info.h"
#include "disk_info.h"
#include "process_info.h"
#include "network_info.h"
#include "system_info.h"

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void ReportGenerator::generateReport() {
    cout << "\nGenerating System Report..." << endl;

    // Open a file stream to write the report
    ofstream reportFile("logs/system_report.txt");

    if (!reportFile.is_open()) {
        cout << "Error: Could not create system_report.txt. Ensure the 'logs' directory exists." << endl;
        return;
    }

    // --- C++ TRICK: Stream Redirection ---
    // We save the original buffer of standard output (cout)
    streambuf* originalCoutBuffer = cout.rdbuf();

    // We redirect standard output (cout) to our text file!
    // Now, anytime a class calls cout << ..., it will write to the file instead of the screen.
    cout.rdbuf(reportFile.rdbuf());

    // Write a header with the current timestamp
    time_t now = time(0);
    char* dt = ctime(&now);
    
    cout << "========================================" << endl;
    cout << "       LINUX SYSTEM MONITOR REPORT      " << endl;
    cout << "========================================" << endl;
    cout << "Generated on: " << dt;
    
    // Instantiate all modules. 
    // They fetch their data in their constructors, and print to the file via cout.
    CPUInfo cpu;
    cpu.printCPUDetails();

    MemoryInfo mem;
    mem.printMemoryDetails();

    DiskInfo disk;
    disk.printDiskDetails();
    
    // For the report, we might not want to print all processes, 
    // but our ProcessInfo class handles it by printing just a sample.
    ProcessInfo proc;
    proc.printProcessDetails();

    NetworkInfo net;
    net.printNetworkDetails();

    SystemInfo sys;
    sys.printSystemUptime();

    cout << "\n========================================" << endl;
    cout << "          END OF REPORT                 " << endl;
    cout << "========================================" << endl;

    // Restore the original cout buffer so printing to the screen works normally again
    cout.rdbuf(originalCoutBuffer);

    reportFile.close();
    
    cout << "Report successfully saved to 'logs/system_report.txt'!" << endl;
}
