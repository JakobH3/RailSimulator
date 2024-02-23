#ifndef JUNCTION_H
#define JUNCTION_H
#include <vector>
#include "Line.h"


class Junction
{
    public:
        std::vector<Line*> linesConnecting;

};

#endif