# Project Requirements and Development Plan (PRD)

## Functional Requirements
1. **CPU Information**: Parse `/proc/cpuinfo` to display CPU model and core count.
2. **Memory Information**: Parse `/proc/meminfo` to display Total, Used, and Available RAM.
3. **Disk Information**: Use Linux APIs/commands to display disk space.
4. **Process Information**: Enumerate the `/proc` directory to list running processes.
5. **Network Information**: Display Hostname and IP address.
6. **System Uptime**: Parse `/proc/uptime` to display system running time.
7. **Report Generation**: Aggregate all data and write to `logs/system_report.txt`.
8. **Driver Demonstration**: A simple character device driver module and a C++ interface to read from it.

## Non-Functional Requirements
- **Compatibility**: Must run on standard Linux distributions (Ubuntu, Debian, etc.).
- **Readability**: Code must be easily readable by beginners, using meaningful variable names and avoiding complex abstractions.
- **Maintainability**: The project is modular. Each feature gets its own class and files.
- **Reliability**: Gracefully handles errors like missing files, permission errors, or invalid user input.

## Development Modules & Timeline
- **Phase 1**: Initial Project Structure & Menu (Completed)
- **Phase 2**: CPU Information Module (Completed)
- **Phase 3**: Memory Information Module (Completed)
- **Phase 4**: Disk Information Module (Completed)
- **Phase 5**: Process Information Module (Completed)
- **Phase 6**: Network Information Module (Completed)
- **Phase 7**: System Uptime Module (Completed)
- **Phase 8**: Report Generation (Completed)
- **Phase 9**: Linux System Programming Demonstration (File Descriptors) (Completed)
- **Phase 10**: Device Driver Demonstration (Completed)
- **Phase 11-13**: Testing, Final Documentation, and Code Cleanup.
