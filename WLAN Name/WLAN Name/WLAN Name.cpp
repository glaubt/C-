#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> getAvailableNetworks() {
    std::ifstream file("/proc/net/wireless");
    std::vector<std::string> networks;

    if (file.is_open()) {
        std::string line;
        // Пропускаем первые две строки
        std::getline(file, line); // заголовок
        std::getline(file, line); // разделитель

        // Читаем остальные строки
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string token;
            // Извлекаем имя сети (интерфейс) из каждой строки
            ss >> token;
            networks.push_back(token);
        }
    }
    else {
        std::cerr << "Unable to open /proc/net/wireless\n";
    }

    return networks;
}

int main() {
    std::vector<std::string> networks = getAvailableNetworks();

    std::cout << "Available Networks:\n";
    for (const auto& network : networks) {
        std::cout << network << std::endl;
    }

    return 0;
}