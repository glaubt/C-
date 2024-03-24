//Register Lion
#include <iostream>
#include <iostream>
#include <string>

using namespace std;

struct User {
    string username;
    string password;
};

void registerUser(User& userDatabase) {
    cout << "Введите имя пользователя: ";
    cin >> userDatabase.username;
    
    cout << "Введите пароль: ";
    cin >> userDatabase.password;
    }

int main() {
    User newUser;

    cout << "Добро пожаловать! Пожалуйста, зарегистрируйтесь.\n";
    registerUser(newUser);

    cout << "Регистрация прошла успешно!\n";

    return 0;
}