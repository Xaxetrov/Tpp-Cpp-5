//
// Created by Edern Haumont on 11/01/2016.
//

#ifndef TP_CPP_5_RECTANGLE_H
#define TP_CPP_5_RECTANGLE_H


#include "Polygon.h"

class Rectangle : public Polygon{

//Public methods
public :

    //Public methods
    const bool Hits(Point aPoint);

    //Constructor
    Rectangle(const std::string aName); //TODO : What if there is less than 3 points ?

//Protected attributes
protected :
    std::vector<Point> points;
};


#endif //TP_CPP_5_RECTANGLE_H
