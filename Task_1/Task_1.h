#ifndef MYTONATEST_TASK_1_H
#define MYTONATEST_TASK_1_H


#include <vector>
#include "../Task.h"

class Task_1 : public Task {
private:
    std::string string;
    char symbol;
public:
    Task_1() = default;
    void launch() final;
    void readString();
    void readSymbol();
    std::vector<std::string> split(std::string source, char delimeter);
};


#endif //MYTONATEST_TASK_1_H
