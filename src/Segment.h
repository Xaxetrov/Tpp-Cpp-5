//
// Created by Edern Haumont on 11/01/2016.
//

#ifndef TP_CPP_5_SEGMENT_H
#define TP_CPP_5_SEGMENT_H

#include "Object.h"

//Constants
static const double EPSILON = 0.5;

class Segment : public Object{

//Public methods
public :

    //Inline getters and setters
    const Point& GetPointA() {return pointA;}
    const Point& GetPointB() {return pointB;}

    //Public methods
    const bool Hits(Point aPoint);
    int Move(int dX, int dY);

    //Constructor
    Segment(std::string aName, Point point1, Point point2);

//Private attributes
private :
    Point pointA;
    Point pointB;
};


#endif //TP_CPP_5_SEGMENT_H
