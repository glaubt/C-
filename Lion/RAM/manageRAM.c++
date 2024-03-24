//Manage Ram
#include <iostream>
int main() {
    // Выделение памяти для целочисленной переменной
    int *ptr = new int;
    // Проверка успешности выделения памяти
    if (ptr == nullptr) {
        std::cerr << "Не удалось выделить память" << std::endl;
        return 1;
    }
    // Присвоение значения выделенной памяти
    *ptr = 10;
    std::cout << "Значение, сохраненное в памяти: " << *ptr << std::endl;
    // Освобождение памяти
    delete ptr;
    ptr = nullptr;
    return 0;
}