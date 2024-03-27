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

Node * getLowestfScore(std::vector<Node> * set)
{

    Node * lowest = nullptr;

    for(std::vector<Node>::iterator i = set->begin(); i != set->end(); ++i)
    {

        if(i->fScore < lowest->fScore)
        {
            lowest = &*i;
        }

    }
    return lowest;

}

void removeNode(std::vector<Node> & set, Node * node)
{

    for(std::vector<Node>::iterator i = set.begin(); i != set.end(); ++i)
    {

        if(i->l == node->l)
        {

            set.erase(i);
            break;
        }

    }

}

std::vector<Line*> Network::getLinesInbetweenLines(Line * l1, Line * l2)
{

    //A* implementation on network network
    std::vector<Line *> ret;
    std::vector<Node> openset;
    std::vector<Node> closedset;
    std::vector<Line *> neighbors;
    Node start;
    start.l = l1;
    start.gScore = __INT32_MAX__;
    start.fScore = __INT32_MAX__;

    openset.push_back(start);

    while(openset.size() != 0)
    {

        Node * current = getLowestfScore(&openset);

        if(current->l == l2)
        {

            //reconstruct path 

        }

        removeNode(openset,current);

        //get neighbors of current 
        // neighbors = current.connectedToStart + current.connectedToEnd
        neighbors.clear();
        neighbors.reserve(current->l->connectedToStart.size() + current->l->connectedToEnd.size());
        neighbors.insert(neighbors.end(), current->l->connectedToStart.begin(), current->l->connectedToStart.end());
        neighbors.insert(neighbors.end(), current->l->connectedToEnd.begin(), current->l->connectedToEnd.end());

        for(std::vector<Line *>::iterator i = neighbors.begin(); i != neighbors.end(); ++i)
        {
            //get tenative g score 
            //check to see if node is in openset 
            // true== check if current gscore is lower and replace gscore and camefrom
            // false== create node for new neighbor set f and g score then add to open set



        }



        





    }

    //return empty set if no route found

}


std::vector<Line*> Network::getLinesInbetweenStations(Station s1, Station s2)
{



}

int Network::distanceBetweenStations(Station s1, Station s2)
{

    

}

