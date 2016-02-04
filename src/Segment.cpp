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

Segment::Segment(Segment &toCopy) : Object(toCopy.name), pointA(toCopy.GetPointA()), pointB(toCopy.GetPointB())
{

}

const bool Segment::Hits(Point aPoint) {
    int x1 = pointA.GetX(), y1 = pointA.GetY(), x2 = pointB.GetX(), y2 = pointB.GetY();
    int x = aPoint.GetX(), y = aPoint.GetY();
    if((x<=max(x1,x2)) && (x>=min(x1,x2)) && (y<=max(x1,x2)) && (y>=min(y1,y2)))
    {
        double dYdXSeg = (y2-y1)/(double)(x2-x1);
        double dYdXTest = (y-y1)/(double)(x-x1);
        if(abs(dYdXSeg-dYdXTest) < EPSILON)
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
    //Calculate vectors'coordinates
    int aX=pointB.GetX()-pointA.GetX();
    int aY=pointB.GetY()-pointA.GetY();
    int bX=othSeg.pointB.GetX()-othSeg.pointA.GetX();
    int bY=othSeg.pointB.GetY()-othSeg.pointA.GetY();

    //Calculate the angle with scalar product
    float sizeA = sqrt(aX*aX+aY*aY);
    float sizeB = sqrt(bX*bX+bY*bY);
    int angle = (int)(acos((aX*bX+aY*bY)/(sizeA*sizeB))*(180/3.14159265358979323846));

    //Calculate the sign with the vectorial product
    int vectorial = aX*bY-aY*bX;
    if(vectorial < 0)
    {
        angle = -1 * angle;
    }

    return angle;
}

string Segment::toString()
{
    return "Segment named "+name;
}

int Segment::GetCommand(ostream &os, string newName)
{
    if(newName == "")
    {
        newName = name;
    }

    os << "S " << newName << " " << pointA.GetX() << " " << pointA.GetY() << " " << pointB.GetX() << " " << pointB.GetY();
    return 0;
}

Object * Segment::Clone()
{
    Object *ptr = new Segment(*this);
    return ptr;
}