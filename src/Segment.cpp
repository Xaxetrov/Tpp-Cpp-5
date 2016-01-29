/***********************************************************************************************************************
    Segment  -  realisation
    -----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#include "Segment.h"
#include <string>
#include <cmath>
#include <iostream>

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
    pointA.Move(dX,dY);
    pointB.Move(dX,dY);
    return 0;
}

int Segment::Angle(Segment othSeg)
{
    int aX=pointB.GetX()-pointA.GetX();
    int aY=pointB.GetY()-pointA.GetY();
    int bX=othSeg.pointB.GetX()-pointB.GetX();
    int bY=othSeg.pointB.GetY()-pointB.GetY();

    float sizeA = sqrt(aX*aX+aY*aY);
    float sizeB = sqrt(bX*bX+bY*bY);

    int angle = (int)(acos((aX*bX+aY*bY)/(sizeA*sizeB))*(180/3.14159265358979323846));

    return angle;
}

string Segment::toString()
{
    return "Segment named "+name;
}

int Segment::GetCommand(ostream &os)
{
    os << "S " << name << " " << pointA.GetX() << " " << pointA.GetY() << " " << pointB.GetX() << " " << pointB.GetY();
    return 0;
}
