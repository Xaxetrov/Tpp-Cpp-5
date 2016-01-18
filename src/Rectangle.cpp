//
// Created by Edern Haumont on 11/01/2016.
//

#include "Rectangle.h"
#include <vector>
#include <string>
using namespace std;

//Public methods

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

    int Rectangle::GetCommand(ostream &os)
    {
        os << "R " << name << " " << points[0].GetX() << " " << points[0].GetY() << " " << points[1].GetX() << " " << points[1].GetY(); //TODO:We can put that back when we found a way to put points in Rectangle.
    }

    //Constructors
    Rectangle::Rectangle(const std::string aName, vector<int> &myCoords) : Polygon(aName,myCoords)
    {
    }

    Rectangle::~Rectangle()
    {
    }