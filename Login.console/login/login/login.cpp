//Login
#include <iostream>
#include <string>

int main() {
    std::string _name;
    std::cout << "Please write your Name: ";
    std::getline(std::cin, _name);

    std::string _password;
    std::cout << "Please write your Password: ";
    std::cin >> _password;
    
    std::cout << "Thank you for login";
}