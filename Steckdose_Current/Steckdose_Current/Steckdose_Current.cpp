//Steckdose (Current)
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

int main() {
    std::cout << "Checking the Current:\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(3,4);

    while (true) {
        int current = dis(gen);

        std::cout << "Current is : " << current << " A\n";

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}
