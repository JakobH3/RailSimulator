#include "Line.h"

Line::Line()
{



}

Segment Line::getClosestSegmentToPoint(Point p)
{

    

}

Point Line::getPointAlongLine(int length, bool direction)
{

    int traveled = 0;

    if(direction)
    {
        return getPointFromStart(traveled,length,startSegment);
    }else
    {
        return getPointFromEnd(traveled,length,endSegment);
    }

}

Point Line::getPointFromStart(int traveled, int length, Segment * current)
{

   int segmentLength = current->location.distanceBetweenPoints(current->next->location);

   if((traveled + segmentLength) < length)
   {
        return getPointFromStart((traveled + segmentLength), length,current->next);
   }else
   {

        float porportion = (traveled - length) / (current->location.distanceBetweenPoints(current->next->location));

        return current->getPointAlongSegment(porportion);
   }

}

Point Line::getPointFromEnd(int traveled, int length, Segment * current)
{
   int segmentLength = current->location.distanceBetweenPoints(current->prev->location);

   if((traveled + segmentLength) < length)
   {
        return getPointFromEnd((traveled + segmentLength), length, current->prev);
   }else
   {

        float porportion = (traveled - length) / (current->location.distanceBetweenPoints(current->prev->location));

        //1 - porportion is to flip direction coming from
        return current->getPointAlongSegment(1 - porportion);
   }


}