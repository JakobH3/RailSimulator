#ifndef SEGMENT_H
#define SEGEMNT_H
#include "Point.h"


class Segment
{

    public:
        Segment * next;
        Segment * prev;
        Point location;
        int trackSpeed;

};



#endif