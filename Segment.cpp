#include "Segment.h"

Segment::Segment(Point location)
{
    this->location = location;
}

Point Segment::getPointAlongSegment(float porportion)
{

    Point endPoint = next->location.scalePoint(-1);
    Point scaledDifference = location.addPoint(endPoint).scalePoint(porportion);
    return scaledDifference.addPoint(location);

}


