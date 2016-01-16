//
// Created by Edern Haumont on 11/01/2016.
//

#include "Polygon.h"
#include <string>
using namespace std;


Polygon::Polygon(const std::string aName) : Object(aName)
{
}

Polygon::~Polygon()
{}

const bool Polygon::Hits(Point aPoint)
{
    return Object::Hits(aPoint);
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
