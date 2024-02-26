#include "Line.h"

Line::Line()
{



}

Line::Line(Segment * start, Segment * end)
{

     startSegment = start;
     endSegment = end;

}

Segment * Line::getClosestSegmentToPoint(Point p)
{
     int closestNum = p.distanceBetweenPoints(startSegment->location);
     Segment * closest = startSegment;
     Segment * cur = startSegment->next;

     while(cur != endSegment)
     {
          
          if(p.distanceBetweenPoints(cur->location) < closestNum)
          {

               closestNum = p.distanceBetweenPoints(cur->location);
               closest = cur;

          }

          cur = cur->next;

     } 
    

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

Line Line::GenerateLineBetweenTwoPoints(Point p1, Point p2, int numSegments)
{
     
     Segment * start = & Segment(p1);
     Segment * current = start;


     for(int i = 1; i < numSegments; i++)
     {
          // nextLoc = (p1-p2)*(i/numSegments) + p1
          Point nextLoc = p1.addPoint(p2.scalePoint(-1)).scalePoint(i/numSegments).addPoint(p1);
          current->next = & Segment(nextLoc);;
          current->next->prev = current;
          current = current->next;

     }

          current->next = & Segment(p2);
          current->next->prev = current;
          
     return Line(start,current);

}