#ifndef NETWORK_INFO_H
#define NETWORK_INFO_H

#include <string>

// The NetworkInfo class is responsible for fetching and displaying basic network details
class NetworkInfo {
public:
    NetworkInfo();
    void printNetworkDetails();

private:
    std::string hostname;
    std::string ipAddress;

    void fetchNetworkData();
};

#endif // NETWORK_INFO_H
