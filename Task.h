#ifndef MYTONATEST_TASK_H
#define MYTONATEST_TASK_H

#include <string>

class Task {
public:
    int number;

    Task() = default;

    virtual void launch() = 0;
};

#endif //MYTONATEST_TASK_H
