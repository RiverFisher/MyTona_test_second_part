#include <iostream>
#include "Task_3.h"
#include "src/List.h"

void Task_3::launch() {
    std::cout << "Task 3. Ultimate Edition. See code in the project structure." << std::endl;

    auto intList = new List<int>;
    auto stringList = new List<std::string>;

    stringList->pushBack("C++ of standard ");
    intList->pushBack(11);

    stringList->popFront();
    intList->popFront();

    std::cout << std::endl;
}
