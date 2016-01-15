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
        return false;
    }

    int Rectangle::Move(int dX, int dY)
    {
        Polygon::Move(dX,dY);
    }

    string Rectangle::toString()
    {
        return "Rectangle named "+name;
    }

    //Constructors
    Rectangle::Rectangle(const std::string aName) : Polygon(aName)
    {
    }

    Rectangle::~Rectangle()
    {
    }