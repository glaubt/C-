//Calculator
#include <iostream>

int main() {
    char operation;
    double num1, num2;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the first symbol (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter the next number: ";
    std::cin >> num2;

    double result;
    switch (operation) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
            result = num1 / num2;
        else {
            std::cerr << "ERROR!" << std::endl;
            return 1;
        }
        break;
    default:
        std::cerr << "ERROR!" << std::endl;
        return 1;
    }

    std::cout << "ANSWER: " << result << std::endl;

    return 0;
}