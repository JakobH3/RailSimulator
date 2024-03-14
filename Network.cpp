#include "Network.h"
#include "Line.h"
#include <vector>

struct Node
{
    Node * cameFrom;
    Line * l;
    int gScore;//distance to node 
    int fScore;//distance from end

};

Node getLowestfScore(std::vector<Node> set)
{

    Node lowest = *set.begin();

    for(std::vector<Node>::iterator i = set.begin(); i != set.end(); ++i)
    {

        if(i->fScore < lowest.fScore)
        {
            lowest = *i;
        }

    }

}

std::vector<Line*> Network::getLinesInbetweenLines(Line * l1, Line * l2)
{

    //A* implementation on network network

    std::vector<Node> openset;
    Node start;
    start.l = l1;
    start.gScore = __INT32_MAX__;
    start.fScore = __INT32_MAX__;

    openset.push_back(start);

    while(openset.size() != 0)
    {



    }



}


std::vector<Line*> Network::getLinesInbetweenStations(Station s1, Station s2)
{



}

int Network::distanceBetweenStations(Station s1, Station s2)
{

    

}

