# 🐧 Linux System Information & Monitoring Tool

Welcome to my **Linux System Monitor**! 👋 

I built this project from scratch as a personal deep dive into **C++** and **Linux System Programming**. If you've ever wondered how tools like `top`, `htop`, or `neofetch` work under the hood, this project is essentially a stripped-down, beginner-friendly version of exactly that. 

Instead of relying on heavy third-party libraries, I wanted to get my hands dirty by directly querying the Linux kernel—parsing `/proc` files, utilizing POSIX APIs, and even exploring a bit of user-space to kernel-space communication.

---

## 💡 Why I Built This

As a developer, I wanted to bridge the gap between application-level C++ and the underlying operating system. My main goals were:
- To understand how the Linux Kernel exposes hardware and system data.
- To practice object-oriented C++ in a highly modular, clean, and readable structure.
- To learn about Makefiles, memory management, file I/O operations, and graceful error handling.
- To experiment with building and communicating with a rudimentary Linux Kernel Module (Device Driver).

---

## 🛠️ Features & How They Work

This tool is driven by an interactive, terminal-based menu. Here's what it can currently do:

- 🧠 **CPU Information:** Parses `/proc/cpuinfo` to extract the processor model, architecture, and core counts.
- 💾 **Memory Usage:** Reads `/proc/meminfo` to calculate Total, Used, and Available RAM in real-time.
- 💽 **Disk Space:** Uses the POSIX `statvfs` struct to determine the total and available capacity of the root (`/`) partition.
- ⚙️ **Process Tracking:** Utilizes `<dirent.h>` to scan the `/proc` directory for active Process IDs (PIDs) and displays a sample list.
- 🌐 **Network Details:** Leverages `gethostname` and `<ifaddrs.h>` to fetch the machine's hostname and external IPv4 addresses.
- ⏱️ **System Uptime:** Converts raw seconds from `/proc/uptime` into a human-readable Hours, Minutes, and Seconds format.
- 📄 **Report Generation:** Uses a cool C++ stream redirection trick (`rdbuf`) to quietly redirect all terminal output into a saved `logs/system_report.txt` file.
- 🚗 **Driver Demonstration:** Attempts to communicate with a custom dummy character device (`/dev/sysmon_dummy`) to show how user-space apps talk to the kernel.

---

## 🏗️ Technologies Used

- **Language:** C++ (C++11/14 standard)
- **APIs:** Native Linux POSIX APIs (`<sys/statvfs.h>`, `<dirent.h>`, `<ifaddrs.h>`)
- **Build System:** GNU Make (`Makefile`)
- **Version Control:** Git

---

## 🚀 Getting Started

### Prerequisites
Because this tool relies heavily on the Linux `/proc` filesystem and POSIX headers, **it will not compile correctly on a native Windows environment** (like MinGW or MSVC). 

You will need a Linux environment:
- **Ubuntu/Debian** (or any Linux distro)
- **WSL (Windows Subsystem for Linux)** 
- A Linux Virtual Machine

*(Note: If you do accidentally run this on Windows, don't worry! I've implemented graceful error handling so the program will catch the missing files and print a friendly error message instead of outright crashing.)*

### Compilation

Clone the repository, navigate into the project folder, and simply run `make`:

```bash
git clone https://github.com/yourusername/Linux-System-Monitor.git
cd Linux-System-Monitor
make
```

### Execution

To run the interactive menu:

```bash
make run
```
*Or, run the binary directly:*
```bash
./bin/system_monitor
```

---

## 🗺️ Project Structure

I tried to keep the architecture as clean as possible. Every feature has its own header and implementation file, making it super easy to extend in the future.

```text
Linux-System-Monitor/
├── bin/                 # Compiled executables live here
├── build/               # Intermediate object files (.o)
├── docs/                # Architecture diagrams, test plans, PRDs
├── driver/              # The demo Linux Kernel Module (.c and Makefile)
├── include/             # C++ Header files (.h)
├── logs/                # Where generated reports are saved
├── src/                 # C++ Source files (.cpp)
├── Makefile             # The build script
└── README.md            # You are here!
```

---

## 🤝 Contributing & Future Plans
Right now, this is mostly a personal educational project, but I plan on eventually adding:
- Real-time CPU usage percentage calculations.
- An ncurses-based UI (like `htop`).
- Network bandwidth monitoring.

Feel free to fork the repo, read through the code, and learn alongside me. Feedback, suggestions, and pull requests are always welcome! 

---
*Built with coffee and curiosity by [Your Name/Handle].*
