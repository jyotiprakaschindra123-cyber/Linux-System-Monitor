#include <iostream>
#include <limits> // for std::numeric_limits
#include "cpu_info.h"
#include "memory_info.h"
#include "disk_info.h"
#include "process_info.h"
#include "network_info.h"
#include "system_info.h"
#include "report_generator.h"
#include "driver_demo.h"

using namespace std;

// Function to display the main menu
void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "       LINUX SYSTEM MONITOR" << endl;
    cout << "========================================" << endl;
    cout << "1. CPU Information" << endl;
    cout << "2. Memory Information" << endl;
    cout << "3. Disk Information" << endl;
    cout << "4. Process Information" << endl;
    cout << "5. Network Information" << endl;
    cout << "6. System Uptime" << endl;
    cout << "7. Generate System Report" << endl;
    cout << "8. Driver Status" << endl;
    cout << "9. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice = 0;
    bool running = true;

    while (running) {
        displayMenu();
        
        // Read user choice
        if (!(cin >> choice)) {
            // Handle invalid input (e.g., characters instead of numbers)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                CPUInfo cpu;
                cpu.printCPUDetails();
                break;
            }
            case 2: {
                MemoryInfo mem;
                mem.printMemoryDetails();
                break;
            }
            case 3: {
                DiskInfo disk;
                disk.printDiskDetails();
                break;
            }
            case 4: {
                ProcessInfo proc;
                proc.printProcessDetails();
                break;
            }
            case 5: {
                NetworkInfo net;
                net.printNetworkDetails();
                break;
            }
            case 6: {
                SystemInfo sys;
                sys.printSystemUptime();
                break;
            }
            case 7: {
                ReportGenerator report;
                report.generateReport();
                break;
            }
            case 8: {
                DriverDemo driver;
                driver.testDriverStatus();
                break;
            }
            case 9:
                cout << "Exiting Linux System Monitor. Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Invalid choice. Please select a number between 1 and 9." << endl;
        }
    }

    return 0;
}
