//Planing your Day
#include <iostream>
#include <fstream>
#include <string>

int getInput(const std::string& prompt) {
    int _value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            break;
        }
        else {
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return _value;
}

std::string loadTextFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string text;
    if (file.is_open()) {
        std::getline(file, text);
        file.close();
    }
    return text;
}

void saveTextToFile(const std::string& text, const std::string& filename) {
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        outfile << text;
        outfile.close();
    }
    else {
        std::cerr << "Error: Unable to open file for writing\n";
    }
}

int main() {

    std::cout << "This is your planning Day console\n";

    //Loading text from last writing.
    std::string text = loadTextFromFile("data.txt");
    if (!text.empty()) {
        std::cout << "Text from previous session: " << text << std::endl;
    }

    //Writing the Data on .txt(Year, Month, Day)
    std::string _year, _month, _day = loadTextFromFile("data.txt");
    if (!text.empty()) {
        std::cout << "Text from previous session: " << _year, _month, _day  << std::endl;
    }

    //Writing the text
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter text: ";
    std::getline(std::cin, text);

    int _year = getInput("Enter Year: ");
    int _month = getInput("Enter Month: ");
    int _day = getInput("Enter Day: ");

    saveTextToFile(text, "data.txt");

    return 0;
}