#include <iostream>
#include "Point.h"
#include "Line.h"

void printPoint(Point p)
{
    std::cout << p.x << "," << p.y << "\n";
}

void printLine(Line l)
{
    Segment * cur = l.startSegment;
    while(cur != l.endSegment)
    {

        printPoint(cur->location);

        cur = cur->next;

    }
}

int main() {

    Point p1 = Point(0,0);
    Point p2 = Point(7000,2000);
    Point p3 = p1.addPoint(p2);
    Point p4 = p3.scalePoint(.5);

    // printPoint(p1);
    // printPoint(p2);
    // printPoint(p3);
    // printPoint(p4);

    Line * l = new Line(p1,p2,10);

    //printLine(l);

    std::cout << l->getLineLength();

    //printPoint(l.endSegment->location);
    

    return 0;
}
