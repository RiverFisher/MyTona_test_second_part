#include "Task_5.h"

void Task_5::launch() {
    std::cout << "Task 5. Final Edition. 2d graphics is easy..." << std::endl;

    std::vector<Point2d *> setOfPoints;
    for (int i = 0; i < 3; i++) {
        std::cout << "Input point for calculating bezier points." << std::endl;
        std::cout << "x-coordinate: ";
        double x;
        std::cin >> x;
        std::cout << "y-coordinate: ";
        double y;
        std::cin >> y;
        auto point = new Point2d(x, y);

        setOfPoints.push_back(point);
    }

    std::vector<Point2d *> selectedPoints = this->getBezierPoints(setOfPoints);

    std::cout << "Coordinates are:" << std::endl;
    for (auto it = selectedPoints.begin(); it != selectedPoints.end(); it++) {
        std::cout << "{" << (*it)->x << ", " << (*it)->y << "}" << std::endl;
    }
}

std::vector<Point2d *> Task_5::getBezierPoints(std::vector<Point2d *> setOfPoints) {
    std::vector<Point2d *> bezierPoints;

    double xMin = setOfPoints.at(0)->x, xMax = xMin;

    for (auto it = setOfPoints.begin(); it != setOfPoints.end(); it++) {
        if ((*it)->x < xMin) xMin = (*it)->x;
        if ((*it)->x > xMax) xMax = (*it)->x;
    }

    int xFrom = (int)xMin, xTo = (int)xMax;
    xFrom   = xFrom < xMin ? xFrom++ : xFrom;
    xTo     = xTo   > xMax ? xTo++   : xTo;

    for (double t = 0; t <= 1; t += PRECISION) {
        int x =
                pow(1 - t, 2)   *   (*setOfPoints[0]).x +
                2 * (1 - t) * t *   (*setOfPoints[1]).x +
                pow(t, 2)       *   (*setOfPoints[2]).x
        ;

        if (x > xFrom && x < xTo) {
            int y =
                    pow(1 - t, 2)   *   (*setOfPoints[0]).y +
                    2 * (1 - t) * t *   (*setOfPoints[1]).y +
                    pow(t, 2)       *   (*setOfPoints[2]).y
            ;

            auto searchPoint = new Point2d(x, y);
            bool wasDiplicate = false;
            for (auto it = bezierPoints.begin(); it != bezierPoints.end(); it++) {
                if ((*it)->x == searchPoint->x && (*it)->y == searchPoint->y) {
                    wasDiplicate = true;
                    break;
                }
            }
            if (!wasDiplicate)
                bezierPoints.push_back(searchPoint);
        }
    }

    return bezierPoints;
}
