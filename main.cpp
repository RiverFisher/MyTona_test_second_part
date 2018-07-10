#include <iostream>
#include <vector>
#include "Task.h"
#include "Task_1/Task_1.h"
#include "Task_2/Task_2.h"
#include "Task_3/Task_3.h"
#include "Task_4/Task_4.h"
#include "Task_5/Task_5.h"


using namespace std;

int main(int argc, char** argv) {
    vector<Task *> tasks = {
            /**
             * You can comment strings below this mark to starting only the concrete tasks
             */
            new Task_1,
            new Task_2,
            new Task_3,
            new Task_4,
            new Task_5
    };

    for (auto it = tasks.begin(); it != tasks.end(); it++) {
        (*it)->launch();
    }

    return 0;
}
