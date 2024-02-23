#ifndef STATION_H
#define STATION_H
#include "Point.h"
#include "Segment.h"
#include "Line.h"

class Station
{

    public: 
        Point location;
        Segment * segment;
        Line * line;
        std::vector<Line*> linesInbetweenStations(Station s1, Station s2);
    
};



#endif