# 🖥️ Multi-Threaded Windows System Monitor

[cite_start]**Technology Stack:** C++11, Windows API, PDH (Performance Data Helper) [cite: 272, 275, 276]
[cite_start]**Core Concepts:** Multi-threading, OS-level API Integration, Real-time Monitoring [cite: 273, 282]

## 📌 Project Overview
[cite_start]A robust, multi-threaded system resource monitoring tool built with C++[cite: 272, 282]. [cite_start]This application utilizes the Windows API and PDH libraries to fetch real-time telemetry data directly from the operating system[cite: 275, 276, 292]. [cite_start]It runs separate threads for different hardware components to ensure non-blocking, continuous monitoring[cite: 282, 283, 284].

## ⚙️ Features
* [cite_start]**Concurrent Monitoring:** Implements `std::thread` to simultaneously track CPU, Memory, and Disk metrics without bottlenecking the main process[cite: 273, 282, 283, 284].
* [cite_start]**CPU Usage:** Uses `PdhOpenQuery` and `PdhCollectQueryData` to calculate exact processor time percentages[cite: 292, 294, 298].
* [cite_start]**RAM Usage:** Leverages `GlobalMemoryStatusEx` to calculate the percentage of physical memory actively in use[cite: 307, 309].
* [cite_start]**Disk Space:** Calculates available and used storage on the C:\ drive using the `GetDiskFreeSpaceEx` API[cite: 317, 321].

## 🚀 How to Run
*Note: This project is designed specifically for Windows environments.*
1. Compile using a C++ compiler that supports C++11 and link the PDH library. For example, using MinGW/GCC:
   `g++ system_monitor.cpp -o sysmon.exe -lpdh`
2. Execute the compiled binary:
   `./sysmon.exe`
