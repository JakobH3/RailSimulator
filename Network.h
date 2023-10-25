#ifndef NETWORK_H
#define NETWORK_H
#include "Line.h"
#include "Junciton.h"
#include "Station.h"

class Network
{

    public:
        Line lines[10];
        Junction junctions[100];
        Station stations[100];

};


#endif