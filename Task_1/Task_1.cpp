#include <iostream>
#include <sstream>
#include "Task_1.h"

void Task_1::launch() {
    std::cout << "Task 1. Free Edition. We are at the paek of technologies..." << std::endl;

    readString();
    readSymbol();
    std::vector<std::string> splittedSubstrings = this->split(this->string, this->symbol);
    std::cout << "Result of the splitting:" << std::endl;
    for (auto it = splittedSubstrings.begin(); it != splittedSubstrings.end(); it++) {
        std::cout << (*it).data() << std::endl;
    }
    std::cout << std::endl;
}

void Task_1::readString() {
    std::cout << "Enter some string: " << std::endl;
    getline(std::cin, this->string);
    std::cout << std::endl;
}

void Task_1::readSymbol() {
    std::cout << "Enter some symbol: " << std::endl;
    std::cin >> this->symbol;
    std::cout << std::endl;
}

std::vector<std::string> Task_1::split(std::string source, char delimeter) {
    std::stringstream ss(source);
    std::string token;
    std::vector<std::string> result;
    while (std::getline(ss, token, delimeter)) {
        result.push_back(token);
    }
    return result;
}
