/***********************************************************************************************************************
    Polygon  -  realisation
    -----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#include "Polygon.h"
#include "Segment.h"
#include <string>
#include <vector>
using namespace std;


Polygon::Polygon(const std::string aName, vector<int> &myCoords) : Object(aName)
{
    for(unsigned int i = 0;i<myCoords.size();i+=2)
    {
        Point tmpPoint(myCoords[i],myCoords[i+1]);
        Add(tmpPoint);
    }
}

Polygon::~Polygon()
{}

const bool Polygon::Hits(Point aPoint)
{
    vector<Point>::iterator i;
    int side = -1;

    for(i = points.begin();i != points.end()-1;i++)
    {
        // A Point is into a polygon is it's at the same size of all his segment

        Segment inPoly("AB",*i,*(i+1));
        Segment toPoint("AP",*i,aPoint);

        int angle = inPoly.Angle(toPoint);
        int tmpSide;
        if(angle > 180)
        {
            tmpSide=1;
        }else
        {
            tmpSide=0;
        }

        if(side = -1)
        {
            side=tmpSide;
        }

        if(side != tmpSide)
        {
            return false;
        }
    }

    // Check on the closing segment
    Segment inPoly("ZA",points.back(),points.front());
    Segment toPoint("ZP",points.back(),aPoint);

    int angle = inPoly.Angle(toPoint);
    int tmpSide;
    if(angle > 180)
    {
        tmpSide=1;
    }
    else
    {
        tmpSide=0;
    }

    if(side != tmpSide)
    {
        return false;
    }

    return true;
}

int Polygon::Move(int dX, int dY)
{
    vector<Point>::iterator i;
    for(i=points.begin();i != points.end(); i++)
    {
        i->Move(dX,dY);
    }
    std::cerr << "Polygon move method called";
    return 0;
}

int Polygon::Add(Point aPoint)
{
    points.push_back(aPoint);
    return 0;
}

string Polygon::toString()
{
    return "Polygon named "+name;
}

int Polygon::GetCommand(std::ostream &os)
{
    os << "PC " << name;
    vector<Point>::iterator i;

    for(i = points.begin();i != points.end(); i++)
    {
        os << " " << i->GetX() << " " << i->GetY();
    }

    return 0;
}