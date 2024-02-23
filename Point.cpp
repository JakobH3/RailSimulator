#include "Point.h"

Point Point::addPoint(Point p)
{

    return Point(x + p.x, y + p.y);

}

Point Point::scalePoint(float p)
{

    return Point((int)x * p, (int)y * p);

}

Point::Point(int x, int y)
{

    this->x = x;
    this->y = y;
    
}



