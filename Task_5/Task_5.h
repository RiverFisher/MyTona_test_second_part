#ifndef MYTONATEST_TASK_5_H
#define MYTONATEST_TASK_5_H


#define PRECISION 0.01

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../Task.h"
#include "Point2d.h"

class Task_5 : public Task {
public:
    void launch() final;

    std::vector<Point2d *> getBezierPoints(std::vector<Point2d *>);
};


#endif //MYTONATEST_TASK_5_H
