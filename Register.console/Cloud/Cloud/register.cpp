//Register
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Please write your Name: ";
    std::getline(std::cin, name);

    int age;
    std::cout << "Please write your Age: ";
    std::cin >> age;

    std::string password;
    std::cout << "Please write your Password: ";
    std::cin >> password;

    char response;
    std::cout << "Can we get your Location? (Y/N): ";
    std::cin >> response;

    std::string location;
    if (response == 'Y' || response == 'y') {
        std::cout << "Please write your Location: ";
        std::cin.ignore();
        std::getline(std::cin, location);
    }
    else {
        std::cout << "Location not provided.\n";
    }

    std::cout << "Thank you for joining up.\n";
    return 0;
}