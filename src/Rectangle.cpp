/***********************************************************************************************************************
    Rectangle  -  realisation
    -------------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

// ------------------------------------------------------------------------------------------------------------ INCLUDES
// Personal includes
#include "Rectangle.h"
// System includes
#include <vector>
#include <string>
using namespace std;

// ------------------------------------------------------------------------------------------------------ CONSTRUCTOR(S)
Rectangle::Rectangle(const std::string aName, vector<int> &myCoords) : Polygon(aName,myCoords)
{
}

Rectangle::Rectangle(Rectangle &toCopy) : Polygon(toCopy)
{

}

Rectangle::~Rectangle()
{
}

// ------------------------------------------------------------------------------------------------------ PUBLIC METHODS
    //Public methods
    const bool Rectangle::Hits(Point aPoint)
    {
        return(aPoint.GetX()>=points[0].GetX()
        && aPoint.GetX()<=points[1].GetX()
        && aPoint.GetY()>=points[0].GetY()
        && aPoint.GetY()<=points[1].GetY());
    }

    string Rectangle::toString()
    {
        return "Rectangle named "+name;
    }

    int Rectangle::GetCommand(ostream &os,string newName)
    {
        if(newName=="")
        {
            newName = name;
        }

        os << "R " << newName << " " << points[0].GetX() << " " << points[0].GetY() << " " << points[1].GetX() << " " << points[1].GetY();
        return 0;
    }

    Object * Rectangle::Clone()
    {
        Object *ptr =  new Rectangle(*this);
        return ptr;
    }