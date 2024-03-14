#include "Line.h"
#include "Point.h"

// Generate Line between two points
Line::Line(Point p1, Point p2, int numSegments)
{

     Segment * start = new Segment(p1);
     Segment * current = start;


     for(int i = 1; i < numSegments; i++)
     {
          // nextLoc = (p2-p1)*(i/numSegments) + p1
          Point nextLoc = p2.subtractPoint(p1).scalePoint(i/(float)numSegments).addPoint(p1);
          //segments.push_back(new Segment(nextLoc));
          current->next = new Segment(nextLoc);
          current->next->prev = current;
          current = current->next;

     }

          current->next = new Segment(p2);
          current->next->prev = current;
          current = current->next;
          
     startSegment = start;
     endSegment = current;

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
    
    return closest;

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

        float porportion =  (traveled - length) / (float) (current->location.distanceBetweenPoints(current->next->location));

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

        float porportion = (traveled - length) / (float) (current->location.distanceBetweenPoints(current->prev->location));

        //1 - porportion is to flip direction coming from
        return current->getPointAlongSegment(1 - porportion);
   }


}

int Line::getLineLength()
{
     return lineLength(startSegment);

}

int Line::lineLength(Segment * cur)
{
     if(cur != endSegment)
     {
          return cur->location.distanceBetweenPoints(cur->next->location) + lineLength(cur->next);
     }else
     {
          return 0;
     }
     

}


bool Line::getDirection(Line * l)
{

     bool ret = false;

     for(std::vector<Line *>::iterator it = connectedToStart.begin(); it != connectedToStart.end(); ++it)
     {

          if(*it == l)
          {
               ret = true;
          }

     }

     return ret;

}