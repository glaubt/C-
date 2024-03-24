//Login User
#include <iostream>
#include <string>

using namespace std;

struct User {
    string username;
    string password;
};

bool login(const User& userDatabase, const string& inputUsername, const string& inputPassword) {
    return (userDatabase.username == inputUsername && userDatabase.password == inputPassword);
}

int main() {
    User userDatabase = {"user", "password"};

    string inputUsername, inputPassword;

    cout << "Введите имя пользователя: ";
    cin >> inputUsername;

    cout << "Введите пароль: ";
    cin >> inputPassword;

    if (login(userDatabase, inputUsername, inputPassword)) {
        cout << "Вход выполнен успешно!" << endl;
    } else {
        cout << "Неверное имя пользователя или пароль." << endl;
    }

    return 0;
}
