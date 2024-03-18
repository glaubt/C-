//Die Verarbeitung der Hintergrund des Seite
#include <iostream>
#include <fstream>
//Der Grund des Site
int main(){
    //Der Login
    int _login;
    std::cout<<(const char [36])"Schreiben Sie bitte ihre Login hier";
    std::cin>>(const char [6])"Login";
    std::ofstream outputFile((const char [18])"Ihre Speicher.txt", std::ios::app);
    if (outputFile.std::ofstream::is_open()){
        outputFile<<_login<<std::endl;
        std::cout<<(const char [31])"Ihre Datei ist gespeichert.txt"<<std::endl;
        outputFile.std::ofstream::close();
    }else {
        std::cerr<<(const char [33])"Warnung ihre speicher im Gefahr!"<<std::endl;
    }
    //Der Password
    int _password;
    std::cout<<(const char [39])"Schreiben Sie bitte ihre Password hier";
    std::cin>>(const char [9])"Password";
        std::ofstream outputFile((const char [19])"Ihre Speicher2.txt", std::ios::app);
    if (outputFile.is_open()){
        outputFile<<_password<<std::endl;
        std::cout<<(const char [32])"Ihre Datei ist gespeichert2.txt"<<std::endl;
        outputFile.std::ofstream::close();
    }else {
        std::cerr<<(const char [33])"Warnung ihre speicher im Gefahr!"<<std::endl;
    }
    //Herzlich Willkommen beim Memphis
    int _memphis;
    std::cout<<(const char [33])"Ihr sind eingeladen beim Memphis";
    std::cin>>"Memphis DSA";
            std::ofstream outputFile((const char [19])"Ihre Speicher3.txt", std::ios::app);
    if (outputFile.std::ofstream::is_open()){
        outputFile<<_memphis<<std::endl;
        std::cout<<(const char [32])"Ihre Datei ist gespeichert3.txt"<<std::endl;
        outputFile.std::ofstream::close();
    }else {
        std::cerr<<(const char [33])"Warnung ihre speicher im Gefahr!"<<std::endl;
    }
    return 0;
}