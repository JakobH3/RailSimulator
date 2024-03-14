#ifndef LINE_H
#define LINE_H
#include <vector>
#include "Segment.h"




class Line
{

    public:
        Segment * startSegment;
        Segment * endSegment;
        std::vector<Line *> connectedToStart;
        std::vector<Line *> connectedToEnd;
        int numTracks;
        
        Point getPointAlongLine(int length, bool direction);
        Point getPointFromStart(int traveled, int length, Segment * current);
        Point getPointFromEnd(int traveled, int length, Segment * current);
        Segment * getClosestSegmentToPoint(Point p);
        std::vector<Line*> getLinesInbetweenLines(Line l1, Line l2);
        int getTripsWithinNofPoint(int n, Point p);
        int getLineLength();
        int lineLength(Segment * cur);
        Line generateLineBetweenTwoPoints(Point p1, Point p2, int numSegments);
        bool getDirection(Line * l);
        Line(Point p1, Point p2, int numSegments);


};




#endif