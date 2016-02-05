/***********************************************************************************************************************
    Polygon  -  realisation
    -----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

// ------------------------------------------------------------------------------------------------------------ INCLUDES
// Personal includes
#include "Polygon.h"
#include "Segment.h"
// System includes
using namespace std;

// ------------------------------------------------------------------------------------------------------ CONSTRUCTOR(S)
Polygon::Polygon(const std::string aName, vector<int> &myCoords) : Object(aName)
{
    for(unsigned int i = 0;i<myCoords.size();i+=2)
    {
        Point tmpPoint(myCoords[i],myCoords[i+1]);
        Add(tmpPoint);
    }
}

Polygon::Polygon(Polygon &toCopy) : Object(toCopy.name)
{
    for(unsigned int i = 0;i<toCopy.points.size();i++)
    {
        Add(toCopy.points[i]);
    }
}

Polygon::~Polygon()
{
}

// ------------------------------------------------------------------------------------------------------ PUBLIC METHODS
const bool Polygon::Hits(Point aPoint)
{
    vector<Point>::iterator i;
    int side = -1;

    for(unsigned int j = 0;j < points.size();j++)
    {
        if((points[j].GetX() == aPoint.GetX()) && (points[j].GetY() == aPoint.GetY()))
        {
            // Check if the point is not a point used to make the polygon
            return true;
        }
    }
    for(i = points.begin();i != points.end()-1;i++)
    {
        if((i->GetX() == aPoint.GetX()) && (i->GetY() == aPoint.GetY()))
        {
            return true;
        }
        // A Point is into a polygon is it's at the same side of all his segment

        Segment inPoly("AB",*i,*(i+1));
        Segment toPoint("AP",*i,aPoint);

        int angle = inPoly.Angle(toPoint);
        int tmpSide;

        if(angle == 0 || angle == 180)
        {
            tmpSide=0;
        }
        else if(angle > 0)
        {
            tmpSide=1;
        }
        else
        {
            tmpSide=2;
        }

        if(side == -1 && tmpSide != 0)
        {
            side=tmpSide;
        }

        if(side != tmpSide && tmpSide != 0)
        {
            return false;
        }
    }

    // Check on the closing segment
    Segment inPoly("ZA",points.back(),points.front());
    Segment toPoint("ZP",points.back(),aPoint);

    int angle = inPoly.Angle(toPoint);
    int tmpSide;
    if(angle == 0 || angle == 180)
    {
        tmpSide=0;
    }
    else if(angle > 0)
    {
        tmpSide=1;
    }
    else
    {
        tmpSide=2;
    }

    return !(side != tmpSide && tmpSide != 0);

}

int Polygon::Move(int dX, int dY)
{
    vector<Point>::iterator i;
    for(i=points.begin();i != points.end(); i++)
    {
        i->Move(dX,dY);
    }
    //std::cerr << "Polygon move method called";
    return 0;
}

string Polygon::toString()
{
    return "Polygon named "+name;
}

int Polygon::GetCommand(ostream &os,string newName)
{
    if(newName == "")
    {
        newName = name;
    }

    os << "PC " << newName;
    vector<Point>::iterator i;

    for(i = points.begin();i != points.end(); i++)
    {
        os << " " << i->GetX() << " " << i->GetY();
    }

    return 0;
}

Object * Polygon::Clone()
{
    Object *ptr = new Polygon(*this);
    return ptr;
}

// --------------------------------------------------------------------------------------------------- PROTECTED METHODS
int Polygon::Add(Point &aPoint)
{
    points.push_back(aPoint);
    return 0;
}