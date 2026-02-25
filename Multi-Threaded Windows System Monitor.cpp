#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <pdh.h>
#pragma comment(lib, "pdh.lib")

class SystemMonitor {
public:
void startMonitoring() {
std::thread cpuThread(&SystemMonitor::monitorCPU, this);
std::thread memoryThread(&SystemMonitor::monitorMemory, this);
std::thread diskThread(&SystemMonitor::monitorDisk, this);

cpuThread.join();
memoryThread.join();
diskThread.join();
}

private:
void monitorCPU() {
PDH_HQUERY cpuQuery;
PDH_HCOUNTER cpuTotal;
PdhOpenQuery(NULL, NULL, &cpuQuery);
PdhAddCounter(cpuQuery, TEXT("\\Processor(_Total)\\% Processor Time"), NULL, &cpuTotal);
PdhCollectQueryData(cpuQuery);

while (true) {
PdhCollectQueryData(cpuQuery);
PDH_FMT_COUNTERVALUE counterVal;
PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);
std::cout << "CPU Usage: " << counterVal.doubleValue << "%" << std::endl;
std::this_thread::sleep_for(std::chrono::seconds(1));
}
}

void monitorMemory() {
while (true) {
MEMORYSTATUSEX memInfo;
memInfo.dwLength = sizeof(MEMORYSTATUSEX);
GlobalMemoryStatusEx(&memInfo);

double totalPhysMem = memInfo.ullTotalPhys;
double physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
double memoryUsage = (physMemUsed / totalPhysMem) * 100.0;

std::cout << "Memory Usage: " << memoryUsage << "%" << std::endl;

std::this_thread::sleep_for(std::chrono::seconds(1));
}
}

void monitorDisk() {
while (true) {
ULARGE_INTEGER freeBytesAvailableToCaller, totalBytes, freeBytes;
GetDiskFreeSpaceEx("C:\\", &freeBytesAvailableToCaller, &totalBytes, &freeBytes);

double totalDisk = totalBytes.QuadPart;
double freeDisk = freeBytes.QuadPart;
double usedDisk = totalDisk - freeDisk;
double diskUsage = (usedDisk / totalDisk) * 100.0;

std::cout << "Disk Usage: " << diskUsage << "%" << std::endl;

std::this_thread::sleep_for(std::chrono::seconds(1));
}
}
};

int main() {
SystemMonitor monitor;
monitor.startMonitoring();
return 0;
} 