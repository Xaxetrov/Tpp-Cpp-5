//
// Created by Edern Haumont on 11/01/2016.
//

#ifndef TP_CPP_5_POLYGON_H
#define TP_CPP_5_POLYGON_H

#include "Object.h"
#include "Point.h"
#include <vector>
#include <string>

class Polygon : public Object{

//Public methods
public :

    //Public methods
    const bool Hits(Point aPoint);
    int Move(int dX, int dY);
    int Add(Point aPoint); //TODO : Do we really want to do this ? That mean that polygon may be empty ?! I just put that for tests.
    std::string toString();

    //Constructor
    Polygon(const std::string aName); //TODO : What if there is less than 3 points ?
    virtual ~Polygon();

//Protected attributes
protected :
    std::vector<Point> points;
};


#endif //TP_CPP_5_POLYGON_H
