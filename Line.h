#ifndef LINE_H
#define LINE_H
#include "Segment.h"
#include "Junciton.h"


class Line
{

    public:
        Segment * startSegment;
        Segment * endSegment;
        Junction * startJunction;
        Junction * endJunction;
        int numTracks;
        
        Point getPointAlongLine(int length, bool direction);
        Point getPointFromStart(int traveled, int length, Segment * current);
        Point getPointFromEnd(int traveled, int length, Segment * current);
        Segment * getClosestSegmentToPoint(Point p);
        std::vector<Line*> getLinesInbetweenLines(Line l1, Line l2);
        int getTripsWithinNofPoint(int n, Point p);
        Line GenerateLineBetweenTwoPoints(Point p1, Point p2, int numSegments);
        Line();
        Line(Segment * start, Segment * end);


};




#endif