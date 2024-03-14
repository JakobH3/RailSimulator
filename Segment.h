#ifndef SEGMENT_H
#define SEGMENT_H
#include "Point.h"


class Segment
{

    public:
        Segment * next;
        Segment * prev;
        Point location;
        int trackSpeed;
        Segment(Point location);
        Point getPointAlongSegment(float i);
        bool isPointAlongSegment(Point p);

};



#endif