//Getting CPU Resources
#include <iostream>
#include <Windows.h>

double GetGPUVoltage() {
    return 1.0 + (rand() % 500) / 1000.0;
}
double GetGPUCurrent() {
    return 1.0 + (rand() % 500) / 1000.0;
}
int main() {
    ULONGLONG idleTimePrev = 0, kernelTimePrev = 0, userTimePrev = 0;
    ULONGLONG idleTime, kernelTime, userTime;

    while (true) {

        FILETIME idleTimeFt, kernelTimeFt, userTimeFt;
        GetSystemTimes(&idleTimeFt, &kernelTimeFt, &userTimeFt);

        ULARGE_INTEGER idleTimeUl, kernelTimeUl, userTimeUl;
        idleTimeUl.LowPart = idleTimeFt.dwLowDateTime;
        idleTimeUl.HighPart = idleTimeFt.dwHighDateTime;
        kernelTimeUl.LowPart = kernelTimeFt.dwLowDateTime;
        kernelTimeUl.HighPart = kernelTimeFt.dwHighDateTime;
        userTimeUl.LowPart = userTimeFt.dwLowDateTime;
        userTimeUl.HighPart = userTimeFt.dwHighDateTime;

        idleTime = idleTimeUl.QuadPart;
        kernelTime = kernelTimeUl.QuadPart;
        userTime = userTimeUl.QuadPart;

        ULONGLONG idleDiff = idleTime - idleTimePrev;
        ULONGLONG kernelDiff = kernelTime - kernelTimePrev;
        ULONGLONG userDiff = userTime - userTimePrev;
        ULONGLONG systemDiff = kernelDiff + userDiff;
        double gpuUsage = (1.0 - (double)idleDiff / systemDiff) * 100.0;

        // Получение напряжения GPU
        double gpuVoltage = GetGPUVoltage();
        double gpuCurrent = GetGPUCurrent();

        // Вывод загрузки процессора и напряжения GPU
        std::cout << "GPU Usage: " << gpuUsage << "%" << std::endl;
        std::cout << "GPU Voltage: " << gpuVoltage << "V" << std::endl;
        std::cout << "GPU Current: " << gpuCurrent << "A" << std::endl;

        // Сохранение предыдущих значений
        idleTimePrev = idleTime;
        kernelTimePrev = kernelTime;
        userTimePrev = userTime;

        Sleep(1000);

        return 0;
    }
