#ifndef MYTONATEST_TASK_2_H
#define MYTONATEST_TASK_2_H

#define INT_MIN -42
#define INT_MAX 42


#include "../Task.h"

class Task_2 : public Task {
private:
    std::vector<int> randomIntegers;
    double average;
    int min, max;
public:
    Task_2() = default;

    void launch() final;

    double getAverage();
    int getMin();
    int getMax();
    Task_2 * recalculateIndicators();

    Task_2 * fillUp(std::vector<int> &);
};


#endif //MYTONATEST_TASK_2_H
