# 🖥️ Multi-Threaded Windows System Monitor

**Technology Stack:** C++11, Windows API, PDH (Performance Data Helper)
**Core Concepts:** Multi-threading, OS-level API Integration, Real-time Monitoring

## 📌 Project Overview
A robust, multi-threaded system resource monitoring tool built with C++. This application utilizes the Windows API and PDH libraries to fetch real-time telemetry data directly from the operating system. It runs separate threads for different hardware components to ensure non-blocking, continuous monitoring.

## ⚙️ Features
* **Concurrent Monitoring:** Implements `std::thread` to simultaneously track CPU, Memory, and Disk metrics without bottlenecking the main process.
* **CPU Usage:** Uses `PdhOpenQuery` and `PdhCollectQueryData` to calculate exact processor time percentages.
* **RAM Usage:** Leverages `GlobalMemoryStatusEx` to calculate the percentage of physical memory actively in use.
* **Disk Space:** Calculates available and used storage on the C:\ drive using the `GetDiskFreeSpaceEx` API.

## 🚀 How to Run
*Note: This project is designed specifically for Windows environments.*
1. Compile using a C++ compiler that supports C++11 and link the PDH library. For example, using MinGW/GCC:
   `g++ -std=c++11 "Multi-Threaded Windows System Monitor.cpp" -o sysmon.exe -lpdh`
2. Execute the compiled binary:
   `./sysmon.exe`
