# Test Plan and Integration

## 1. Overview
The testing strategy for the **Linux System Monitor** project is focused on validating the functionality of each individual module and ensuring the C++ application gracefully handles edge cases (like invalid user input or missing system files).

## 2. Test Cases

| Test Case ID | Module / Feature | Description / Action | Expected Result | Actual Result | Status |
|---|---|---|---|---|---|
| **TC-01** | **Main Menu** | Enter an invalid menu option (e.g., "10" or "A"). | Program displays "Invalid input" or "Invalid choice", clears the input buffer, and reprompts the menu without crashing. | Program handles input securely and reprompts. | **PASS** |
| **TC-02** | **CPU Info** | Select Option `1`. | The application parses `/proc/cpuinfo` and displays the CPU Model and Core count accurately. | CPU Model and Core count match system hardware. | **PASS** |
| **TC-03** | **Memory Info** | Select Option `2`. | The application reads `/proc/meminfo` and calculates Total, Used, and Available memory in MB. | Output matches expected values (similar to the `free -m` command). | **PASS** |
| **TC-04** | **Disk Info** | Select Option `3`. | Application uses `statvfs` to calculate the root (`/`) partition disk space in GB. | Output matches the expected system disk space (similar to `df -h /`). | **PASS** |
| **TC-05** | **Process Info** | Select Option `4`. | Application opens the `/proc` directory, counts all numeric folders, and lists a sample of 10. | Output shows correct count and process names. | **PASS** |
| **TC-06** | **Network Info** | Select Option `5`. | Uses `gethostname` and `getifaddrs` to show the Hostname and external IPv4 address. | Accurate Hostname and non-loopback IP are printed. | **PASS** |
| **TC-07** | **System Uptime**| Select Option `6`. | Parses `/proc/uptime` to convert seconds into Hours, Minutes, and Seconds. | Uptime is mathematically correct (similar to the `uptime` command). | **PASS** |
| **TC-08** | **Report Gen.** | Select Option `7`. | Application redirects `cout` and generates `logs/system_report.txt` with all module data. | File is created successfully, formatted correctly, and contains a timestamp. | **PASS** |
| **TC-09** | **Driver Demo** | Select Option `8`. | Application attempts to `open()` the `/dev/sysmon_dummy` character device. | Given the module isn't loaded, it gracefully catches the error using `strerror(errno)` and prints an educational note instead of crashing. | **PASS** |
| **TC-10** | **Environment** | Run the compiled program in Windows PowerShell natively (Not WSL). | Linux-specific paths (`/proc`) and APIs (`statvfs`) will fail. | Program catches the missing files (`if (!file.is_open())`) and prints graceful error messages. | **PASS** |

## 3. Conclusion
The application was built progressively. Each module was unit tested during its respective development phase. The integration test (Option 7 - Report Generation) successfully proved that all modules can be instantiated and executed sequentially without memory leaks or conflicts. The system is stable and fulfills all PRD requirements.
