#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

// The SystemInfo class fetches and displays the system uptime
class SystemInfo {
public:
    SystemInfo();
    void printSystemUptime();

private:
    double uptimeSeconds;
    int hours;
    int minutes;
    int seconds;

    void fetchUptimeData();
};

#endif // SYSTEM_INFO_H
