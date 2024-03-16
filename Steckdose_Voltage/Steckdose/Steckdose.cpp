#include <iostream>
#include <chrono>
#include <thread>
#include <random>

int main() {
    std::cout << "Checking the Voltage and Current:\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(224, 230);

    while (true) {
        int voltage = dis(gen);

        std::cout << "Voltage is : " << voltage << " V\n";

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}
