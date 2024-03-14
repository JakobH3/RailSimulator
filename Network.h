#ifndef NETWORK_H
#define NETWORK_H
#include "Line.h"
#include "Station.h"

class Network
{

    public:
        std::vector<Line> lines;
        std::vector<Station> stations;
        //std::vector<Route> routes;
        //std::vector<Trip> trips;
        int distanceBetweenStations(Station s1, Station s2);
        std::vector<Line*> getLinesInbetweenStations(Station s1, Station s2); 
        std::vector<Line*> getLinesInbetweenLines(Line * l1, Line * l2);
        Line getClosestLineToPoint(Point p);

};


#endif