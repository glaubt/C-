//Лион ядро
#include <iostream>
#include <vector>
#include <string>

// Пример базового класса процесса
class Process {
private:
    std::string name;
    int pid;
public:
    Process(std::string _name, int _pid) : name(_name), pid(_pid) {}
    void execute() {
        std::cout << "Process " << name << " with PID " << pid << " is executing.\n";
    }
};

// Пример класса планировщика процессов
class Scheduler {
private:
    std::vector<Process> processes;
public:
    void addProcess(Process process) {
        processes.push_back(process);
    }
    void executeProcesses() {
        for (auto& process : processes) {
            process.execute();
        }
    }
};

// Пример класса операционной системы
class OperatingSystem {
private:
    Scheduler scheduler;
public:
    void boot() {
        std::cout << "Booting the operating system...\n";
        // Создаем несколько процессов
        Process process1("Interface", 1);
        Process process2("CMD", 2);
        Process process3("Google", 3);
        
        // Добавляем процессы в планировщик
        scheduler.addProcess(process1);
        scheduler.addProcess(process2);
        scheduler.addProcess(process3);
    }
    
    void runProcesses() {
        std::cout << "Executing processes...\n";
        // Запускаем выполнение процессов
        scheduler.executeProcesses();
    }
};

int main() {
    OperatingSystem os;
    os.boot(); 
    os.runProcesses(); 
    return 0;
}