//
// Created by Edern Haumont on 11/01/2016.
//

#include "Polygon.h"
#include <string>
#include <vector>
using namespace std;


Polygon::Polygon(const std::string aName, vector<int> &myCoords) : Object(aName)
{
    for(int i = 0;i<myCoords.size();i+=2)
    {
        Point tmpPoint(myCoords[i],myCoords[i+1]);
        Add(tmpPoint);
    }
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