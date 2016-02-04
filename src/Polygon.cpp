/***********************************************************************************************************************
    Polygon  -  realisation
    -----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

//-------------------------------------------------------------------------------------------------------------- INCLUDE
//----------------------------------------------------------------------------------------------------- Personal include
#include "Polygon.h"
#include "Segment.h"
using namespace std;

//--------------------------------------------------------------------------------------------------------------- PUBLIC
//------------------------------------------------------------------------------------------------------- Public methods

const bool Polygon::Hits(Point aPoint)
// Algorithm :
// 1 - A Point is into a polygon if it it's size equals the sum of those of all its segments
// 2 - Check on the closing segment
{
    vector<Point>::iterator i;
    int side = -1;

    for(i = points.begin();i != points.end()-1;i++)
    {
        // 1st test

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

    // 2nd test
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
// Algorithm :
// Point by Point move.
{
    vector<Point>::iterator i;
    for(i=points.begin();i != points.end(); i++)
    {
        i->Move(dX,dY);
    }
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

//------------------------------------------------------------------------------------------- Constructors - Destructors
// Constructor
Polygon::Polygon(const std::string aName, vector<int> &myCoords) : Object(aName)
{
    for(unsigned int i = 0;i<myCoords.size();i+=2)
    {
        Point tmpPoint(myCoords[i],myCoords[i+1]);
        Add(tmpPoint);
    }
}

// Copy constructor
Polygon::Polygon(Polygon &toCopy) : Object(toCopy.name)
{
    for(unsigned int i = 0;i<toCopy.points.size();i++)
    {
        Add(toCopy.points[i]);
    }
}

// Destructor
Polygon::~Polygon()
{}