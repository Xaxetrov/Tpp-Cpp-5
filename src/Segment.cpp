//
// Created by Edern Haumont on 11/01/2016.
//

#include "Segment.h"

using namespace std;

Segment::Segment(std::string aName, Point point1, Point point2) : Object(aName), pointA(point1), pointB(point2)
{

}

const bool Segment::Hits(Point aPoint) {
    int x1 = pointA.GetX(), y1 = pointA.GetY(), x2 = pointB.GetX(), y2 = pointB.GetY();
    int x = aPoint.GetX(), y = aPoint.GetY();
    if(x<max(x1,x2) && x>min(x1,x2) && y<max(x1,x2) && y>max(y1,y2))
    {
        double dYdXSeg = (y2-y1)/(x2-x1);
        double dYdXTest = (y-y1)/(x-x1);
        if(dYdXSeg-dYdXTest < EPSILON)
        {
            return true;
        }
    }
    return false;
}

int Segment::Move(int dX, int dY) {
    
    return 0;
}
