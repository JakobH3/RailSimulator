#include "Point.h"
#include <math.h>

Point Point::addPoint(Point p)
{

    return Point(x + p.x, y + p.y);

}

Point Point::subtractPoint(Point p)
{

    return Point(x - p.x, y - p.y);

}

Point Point::scalePoint(float p)
{

    return Point((int)x * p, (int)y * p);

}

int Point::distanceBetweenPoints(Point p)
{

    int xDif = x - p.x;
    int yDif = y - p.y;

    return (int) sqrt((xDif * xDif) + (yDif * yDif));

}

Point::Point(int x, int y)
{

    this->x = x;
    this->y = y;
    
}

Point::Point()
{

}




