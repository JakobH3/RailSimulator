#ifndef POINT_H
#define POINT_H



class Point
{

    public:
        int x,y;
        Point(int x,int y);
        Point addPoint(Point p);
        Point scalePoint(int p);

};

#endif