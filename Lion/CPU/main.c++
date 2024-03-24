//Лион ядро
#include <iostream>
#include <thread>// вы получаете доступ к классам и функциям, позволяющим создавать, управлять и синхронизировать потоки выполнения в вашей программе
#include <vector>//который предоставляет удобный интерфейс для работы с динамическими массивами
#include <mutex>// вы получаете доступ к классам и функциям для работы с мьютексами, такими как std::mutex, std::lock_guard и другими.


// Простая реализация микроядра
    class Microkernel {
    private:
    std::mutex mutex_;
    std::vector<std::thread> threads_;

    public:
    void createThread(void (*func)()) {
        std::lock_guard<std::mutex> lock(mutex_);
        threads_.push_back(std::thread(func));
    }

    void joinAll() {
        for (auto& thread : threads_) {
            if (thread.joinable())
                thread.join();
        }
    }
};

// Пример функции, которая будет выполняться в потоке
void CPU() {
    std::cout << "This comes out" << std::endl;
}

int main() {
    Microkernel kernel;

    // Создание потока с примерной функцией
    kernel.createThread(CPU);

    // Ждем завершения всех потоков
    kernel.joinAll();

    return 0;
}
