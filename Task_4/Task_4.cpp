#include "Task_4.h"
#include "../config.h"

void Task_4::launch() {
    std::cout << "Task 4. Collection Edition. We can work with strings..." << std::endl;

    std::string fileDirectory = FILES_TASK_DIR, fileName = "input.txt";

    std::ifstream file(fileDirectory + fileName);
    std::string line;
    while (std::getline(file, line)) {
        std::string delimeter = ":";
        std::size_t found = line.find(delimeter);

        if (found != std::string::npos) {
            std::string keySubstring = line.substr(0, found);
            std::string valueSubstring = line.substr(found + 1, line.length());
            std::cout << "Key: " << keySubstring << " " << "Value: " << valueSubstring << std::endl;
        } else {
            std::cout << "Line is incorrect" << std::endl;
        }
    }
    std::cout << std::endl;
}
