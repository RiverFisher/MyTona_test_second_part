#include <vector>
#include <iostream>
#include "Task_2.h"

void Task_2::launch() {
    std::cout << "Task 2. Enterprice Edition. We are on a relax..." << std::endl;

    Task_2 * thisObject = this->fillUp(this->randomIntegers);

    std::cout << "Average is: " << thisObject->getAverage() << std::endl
              << "Min is: "     << thisObject->getMin()     << std::endl
              << "Max is: "     << thisObject->getMax()     << std::endl
                                                            << std::endl;
}

double Task_2::getAverage() {
    return this->average;
}

int Task_2::getMin() {
    return this->min;
}

int Task_2::getMax() {
    return this->max;
}

Task_2* Task_2::recalculateIndicators() {
    int sum = 0, count = 0, min = this->randomIntegers.front(), max = min;
    for (auto it = this->randomIntegers.begin();
         it != this->randomIntegers.end();
         it++, count++) {
        /**
         * Handling for calculating of average
         */
        sum += *it;

        /**
         * Handling for calculating of min
         */
        if (*it < min) min = *it;

        /**
         * Handling for calculating of max
         */
        if (*it > max) max = *it;
    }

    this->average = (double)sum / count;
    this->min = min;
    this->max = max;

    return this;
}

Task_2 * Task_2::fillUp(std::vector<int> &randomIntegers) {
    srand((unsigned)time(nullptr));

    for (int it = 0; it < 100; it++) {
        randomIntegers.push_back(INT_MIN + rand() % (INT_MAX - INT_MIN));
    }

    /**
     * Post-processing event
     */
    return this->recalculateIndicators();
}
