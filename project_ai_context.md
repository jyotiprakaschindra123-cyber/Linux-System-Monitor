# AI Project Context & Conversation Summary
*(Note: Excluded from Git Repository)*

## Project Context
- **Project Title:** Linux System Information & Monitoring Tool
- **User Constraints:** Beginner-friendly, easily readable C++, modular structure, no overly advanced design patterns/templates, must be easy to explain in an interview.
- **Environment:** The user is developing on a Windows machine but the code targets Linux. The user was advised to compile and test using WSL (Windows Subsystem for Linux) or a Linux VM because of Linux-specific APIs.

## What Was Built
1. **Menu System (`main.cpp`)**: A `while(true)` loop with a `switch` statement that calls different modules.
2. **CPU Info (`cpu_info.cpp`)**: Parses `/proc/cpuinfo` to get Model and Cores.
3. **Memory Info (`memory_info.cpp`)**: Parses `/proc/meminfo` to calculate Total, Used, and Available RAM.
4. **Disk Info (`disk_info.cpp`)**: Uses POSIX `statvfs` to check root (`/`) partition space in GB.
5. **Process Info (`process_info.cpp`)**: Uses POSIX `<dirent.h>` to scan `/proc` for numeric folders (PIDs), counts them, and lists a sample of 10.
6. **Network Info (`network_info.cpp`)**: Uses POSIX `gethostname` and `<ifaddrs.h>` to get hostname and external IPv4 address.
7. **System Uptime (`system_info.cpp`)**: Parses `/proc/uptime` and converts raw seconds to Hours, Minutes, Seconds.
8. **Report Generator (`report_generator.cpp`)**: Uses a C++ stream redirection trick (`rdbuf`) to temporarily redirect `std::cout` to write all module outputs to `logs/system_report.txt`.
9. **Linux Driver Demo (`driver_demo.cpp` & `simple_monitor_driver.c`)**: A dummy kernel module and a user-space app that tries to communicate with `/dev/sysmon_dummy` using raw system calls (`open`, `read`, `close`).

## Documentation Generated
- `docs/project_introduction.md`
- `docs/PRD.md` (Project Requirements and Development Plan)
- `docs/architecture.md` (Contains Mermaid UML Diagrams)
- `docs/test_plan.md`
- `docs/interview_questions.md` (Private, ignored in git)

## Git Strategy
The user wanted to push the project "little by little" over several days to simulate a realistic development cycle. A custom day-by-day `git add` and `git commit` schedule was provided to them in the conversation.

## Future AI Instructions
If a new AI session is started and this file is read:
- **Do NOT** rewrite the project to be highly complex. Keep the code extremely simple and readable.
- **Do NOT** remove the graceful error handling that prevents crashes on Windows native compilation.
- Understand that the code is finalized as per the user's initial requirements. Any additions should follow the same modular pattern (header in `include/`, implementation in `src/`, integrated into `main.cpp`).
