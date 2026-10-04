#include "driver_demo.h"
#include <iostream>
#include <fcntl.h>   // For open() system call
#include <unistd.h>  // For read() and close() system calls
#include <cstring>   // For strerror()
#include <cerrno>    // For errno

using namespace std;

void DriverDemo::testDriverStatus() {
    cout << "\n--- Driver Status Demonstration ---" << endl;
    cout << "Attempting to communicate with '/dev/sysmon_dummy'..." << endl;

    // SYSTEM CALL: open()
    // This is a direct request to the Linux kernel to open a file descriptor.
    int file_descriptor = open("/dev/sysmon_dummy", O_RDONLY);

    if (file_descriptor < 0) {
        cout << "\n[!] Driver Unavailable." << endl;
        cout << "Reason: " << strerror(errno) << endl;
        cout << "\nNote:" << endl;
        cout << "In a real Linux environment, you would need to compile the driver located in" << endl;
        cout << "the 'driver/' folder, load it using 'insmod', and create the device node" << endl;
        cout << "using 'mknod' before this user-space application can read from it." << endl;
    } else {
        // SYSTEM CALL: read()
        char receive_buffer[256];
        int bytes_read = read(file_descriptor, receive_buffer, sizeof(receive_buffer));
        
        if (bytes_read >= 0) {
            receive_buffer[bytes_read] = '\0'; // Null-terminate the string
            cout << "\n[+] Driver is ACTIVE and communicating!" << endl;
            cout << "Message from Kernel Space: " << receive_buffer << endl;
        } else {
            cout << "\n[-] Failed to read from the driver." << endl;
        }

        // SYSTEM CALL: close()
        close(file_descriptor);
    }
    cout << "-----------------------------------" << endl;
}
