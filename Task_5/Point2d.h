#ifndef MYTONATEST_POINT2D_H
#define MYTONATEST_POINT2D_H

struct Point2d {
    double x;
    double y;

    Point2d() = default;

    Point2d(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

#endif //MYTONATEST_POINT2D_H
