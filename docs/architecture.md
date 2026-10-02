# System Design and Architecture

## 1. System Architecture Diagram
The architecture of this project is a simple User-Space C++ Application that interfaces with the Linux Kernel via system calls and pseudo-filesystems.

```mermaid
graph TD
    A[User Space: C++ Application] -->|Reads /proc| B(Linux VFS /proc)
    A -->|System Calls| C(Linux Kernel)
    C --> D[Hardware: CPU, RAM, Disk]
    B -.-> D
```

## 2. Class Diagram
The C++ application uses a modular, object-oriented design where each system component being monitored is encapsulated within its own class.

```mermaid
classDiagram
    class CPUInfo {
        -string modelName
        -int cores
        +CPUInfo()
        -fetchCPUData()
        +printCPUDetails()
    }
    
    class MemoryInfo {
        -long long totalMemory
        -long long availableMemory
        -long long usedMemory
        +MemoryInfo()
        -fetchMemoryData()
        +printMemoryDetails()
    }

    class DiskInfo {
        -long long totalSpace
        -long long availableSpace
        -long long usedSpace
        +DiskInfo()
        -fetchDiskData()
        +printDiskDetails()
    }

    class ProcessInfo {
        -int totalProcesses
        -vector processList
        +ProcessInfo()
        -fetchProcessData()
        +printProcessDetails()
    }

    class NetworkInfo {
        -string hostname
        -string ipAddress
        +NetworkInfo()
        -fetchNetworkData()
        +printNetworkDetails()
    }

    class SystemInfo {
        -double uptimeSeconds
        -int hours
        -int minutes
        -int seconds
        +SystemInfo()
        -fetchUptimeData()
        +printSystemUptime()
    }

    class ReportGenerator {
        +generateReport()
    }

    class DriverDemo {
        +testDriverStatus()
    }

    class Main {
        +displayMenu()
        +main()
    }

    Main --> CPUInfo : Instantiates
    Main --> MemoryInfo : Instantiates
    Main --> DiskInfo : Instantiates
    Main --> ProcessInfo : Instantiates
    Main --> NetworkInfo : Instantiates
    Main --> SystemInfo : Instantiates
    Main --> ReportGenerator : Instantiates
    Main --> DriverDemo : Instantiates
    ReportGenerator --> CPUInfo : Uses
    ReportGenerator --> MemoryInfo : Uses
```

## 3. Sequence Diagram (Example: Reading Memory)
```mermaid
sequenceDiagram
    participant User
    participant Main
    participant MemoryInfo
    participant Linux_ProcFS
    
    User->>Main: Enters '2'
    Main->>MemoryInfo: create object (mem)
    MemoryInfo->>MemoryInfo: fetchMemoryData()
    MemoryInfo->>Linux_ProcFS: std::ifstream("/proc/meminfo")
    Linux_ProcFS-->>MemoryInfo: returns memory data stream
    MemoryInfo-->>Main: Object initialized
    Main->>MemoryInfo: mem.printMemoryDetails()
    MemoryInfo-->>User: Prints Total, Used, Available RAM
```

## 4. Developer Notes
- **Encapsulation**: All data fetching happens automatically in the constructors of the classes, keeping `main.cpp` extremely clean and simple.
- **Git Strategy**: We are committing code sequentially after each functional module is developed.
