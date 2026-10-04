# Interview Preparation Guide
*(Note: Excluded from Git Repository)*

## Project Questions

**Q: What problem does the project solve?**
A: It consolidates vital Linux system information (CPU, RAM, Disk, Processes, Network) into a single, easy-to-read command-line interface. Instead of a user having to memorize and run multiple commands (like `free`, `df`, `uptime`, `ps`), they can use this one tool.

**Q: Why did you choose this project?**
A: I chose it to solidify my understanding of C++ Object-Oriented Programming while simultaneously learning about Linux internals, system calls, and the `/proc` virtual filesystem. 

**Q: What are the main features?**
A: It provides real-time data on CPU, Memory, Disk space, running Processes, Network configuration, and System Uptime. It also features an automated report generator and a demonstration of how a user-space app communicates with a kernel device driver.

**Q: What is the architecture?**
A: It is a modular User-Space C++ application. The `main.cpp` handles the menu routing, and each specific feature is encapsulated in its own class (e.g., `CPUInfo`, `MemoryInfo`). These classes fetch data directly from the Linux Kernel either via pseudo-files (like `/proc`) or standard POSIX system APIs.

---

## C++ Questions

**Q: Why C++?**
A: C++ provides high-level object-oriented features (making the code clean and modular) while still providing low-level access to memory and POSIX C APIs necessary for system programming.

**Q: What classes did you create?**
A: `CPUInfo`, `MemoryInfo`, `DiskInfo`, `ProcessInfo`, `NetworkInfo`, `SystemInfo`, `ReportGenerator`, and `DriverDemo`.

**Q: What is encapsulation?**
A: Encapsulation is hiding the internal state and functionality of an object. For example, my `MemoryInfo` class has private variables for `totalMemory` and `usedMemory`. `main.cpp` can't change these variables; it can only call the public `printMemoryDetails()` method.

**Q: Why use vector?**
A: I used `std::vector` in the `ProcessInfo` class to store a list of running processes. Vectors are dynamic arrays that automatically manage their own memory, meaning I don't have to worry about memory leaks or hardcoding an array size.

**Q: How does file handling work?**
A: I used `<fstream>`. Specifically, `std::ifstream` to read virtual files like `/proc/meminfo`, and `std::ofstream` to write the system report to `logs/system_report.txt`.

**Q: How does exception/error handling work?**
A: Instead of throwing complex exceptions, I used defensive programming. Before reading a file, I check `if (!file.is_open())`. For system calls like `open()`, I check if the returned file descriptor is `< 0`, and if so, I use `strerror(errno)` to print exactly why it failed.

---

## Linux Questions

**Q: What is Linux?**
A: Linux is a family of open-source Unix-like operating systems based on the Linux kernel. It acts as the bridge between the computer's hardware and the software applications.

**Q: What is `/proc`?**
A: It is a "pseudo-filesystem". It doesn't exist on the hard drive; it is created in RAM by the Linux kernel. It provides a way for user-space applications to read real-time data directly from the kernel (like CPU stats or running processes).

**Q: What is `/sys`?**
A: Similar to `/proc`, it's a virtual filesystem, but it is heavily focused on hardware devices and drivers rather than processes.

**Q: What is a process?**
A: A process is an instance of a running program. 

**Q: What is a PID?**
A: Process ID. It is a unique number the Linux kernel assigns to every running process to keep track of them.

**Q: What is a file descriptor?**
A: It is an integer that acts as a "handle" or reference to an open file or device. When you call `open()`, the kernel returns a file descriptor (like `3`), which you then pass to `read()` or `write()`.

---

## System Programming Questions

**Q: What is a system call?**
A: It is a programmatic request for a service from the kernel. Because user applications cannot access hardware directly, they must "ask" the kernel to do it for them via a system call.

**Q: What is user space?**
A: The restricted memory area where normal applications (like our C++ program) run.

**Q: What is kernel space?**
A: The protected memory area where the core operating system and device drivers run, with full access to hardware.

**Q: What do open(), read(), write() do?**
A: They are fundamental POSIX system calls. `open()` requests access to a file/device and returns a file descriptor. `read()` pulls bytes from that descriptor into a buffer. `write()` pushes bytes from a buffer to the descriptor.

---

## Device Driver Questions

**Q: What is a kernel module?**
A: It is a piece of code that can be loaded into the Linux kernel dynamically at runtime without needing to reboot.

**Q: What is a character device?**
A: A device that transmits data character-by-character (or byte-by-byte), like a keyboard or a serial port. 

**Q: What does insmod do?**
A: It is a terminal command used to insert (load) a module into the kernel.

**Q: What does rmmod do?**
A: It removes an active module from the kernel.

**Q: What is printk?**
A: It is the kernel's version of `printf`. Since kernel space doesn't have a standard terminal output, `printk` writes messages to the kernel log.

**Q: What is dmesg?**
A: A terminal command used to view the kernel log (where `printk` messages go).

**Q: How does user space communicate with the driver?**
A: The driver creates a device file in the `/dev/` directory. The user-space app uses `open()`, `read()`, and `write()` on that file, and the kernel translates those calls into the driver's specific functions.

---

## Git & SDLC Questions

**Q: Why use Git?**
A: To track changes in my source code, maintain a history of my work, and allow me to roll back if a new feature breaks the project.

**Q: What is a commit?**
A: A saved snapshot of the project at a specific point in time. I used meaningful, phase-by-phase commits to show my development timeline.

**Q: What are your requirements (SDLC)?**
A: We defined Functional requirements (what the system should do, like read CPU info) and Non-Functional requirements (how it should do it, like code readability and error handling) in the PRD document.

**Q: How did you test the project?**
A: I did unit testing for each module as it was developed, ensuring graceful failure on Windows and accurate data parsing on Linux. I formalized this in the `test_plan.md`.
