#include "network_info.h"
#include <iostream>
#include <unistd.h>      // For gethostname()
#include <ifaddrs.h>     // For getifaddrs()
#include <arpa/inet.h>   // For inet_ntoa()
#include <netinet/in.h>  // For struct sockaddr_in

using namespace std;

NetworkInfo::NetworkInfo() {
    hostname = "Unknown";
    ipAddress = "Unknown";
    fetchNetworkData();
}

void NetworkInfo::fetchNetworkData() {
    // 1. Get Hostname
    char hostBuffer[256];
    if (gethostname(hostBuffer, sizeof(hostBuffer)) == 0) {
        hostname = hostBuffer;
    }

    // 2. Get IP Address
    struct ifaddrs *interfaces = nullptr;
    struct ifaddrs *tempAddr = nullptr;

    // getifaddrs creates a linked list of structures describing the network interfaces
    if (getifaddrs(&interfaces) == 0) {
        tempAddr = interfaces;
        while (tempAddr != nullptr) {
            // Check if it is an IPv4 address (AF_INET)
            if (tempAddr->ifa_addr && tempAddr->ifa_addr->sa_family == AF_INET) {
                // Ignore the loopback interface ("lo" / 127.0.0.1)
                string interfaceName = tempAddr->ifa_name;
                if (interfaceName != "lo") {
                    // Convert the IP address from a struct into a readable string
                    struct sockaddr_in *pAddr = (struct sockaddr_in *)tempAddr->ifa_addr;
                    ipAddress = inet_ntoa(pAddr->sin_addr);
                    break; // Stop after finding the first active external IPv4 address
                }
            }
            tempAddr = tempAddr->ifa_next; // Move to the next interface in the linked list
        }
    }
    // Free the memory allocated by getifaddrs
    if (interfaces != nullptr) {
        freeifaddrs(interfaces);
    }
}

void NetworkInfo::printNetworkDetails() {
    cout << "\n--- Network Information ---" << endl;
    cout << "Hostname   : " << hostname << endl;
    cout << "IP Address : " << ipAddress << endl;
    cout << "---------------------------" << endl;
}
