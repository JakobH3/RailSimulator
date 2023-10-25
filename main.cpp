#include <iostream>
#include "Point.h"

void printPoint(Point p)
{
    std::cout << p.x << "," << p.y << "\n";
}

int main() {

    Point p1 = Point(1,2);
    Point p2 = Point(2,3);
    Point p3 = p1.addPoint(p2);
    Point p4 = p3.scalePoint(2);

    printPoint(p1);
    printPoint(p2);
    printPoint(p3);
    printPoint(p4);

    return 0;
}
