#include "Segment.h"
#include "Point.h"

Segment::Segment(Point loc)
{
    location = loc;
}

Point Segment::getPointAlongSegment(float porportion)
{

    Point endPoint = next->location.scalePoint(-1);
    Point scaledDifference = location.addPoint(endPoint).scalePoint(porportion);
    return scaledDifference.addPoint(location);

}


