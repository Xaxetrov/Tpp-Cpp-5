/***********************************************************************************************************************
    Segment  -  description
    -----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#ifndef TP_CPP_5_SEGMENT_H
#define TP_CPP_5_SEGMENT_H

#include "Object.h"
#include "Point.h"
#include <string>
#include <iostream>

//Constants
static const double EPSILON = 0.1;

class Segment : public Object{

//Public methods
public :

    //Inline getters and setters
    const Point& GetPointA() {return pointA;}
    const Point& GetPointB() {return pointB;}

    //Public methods
    const bool Hits(Point aPoint);
    virtual int Move(int dX, int dY);
    int Angle(Segment othSeg);
    std::string toString();
    int GetCommand(std::ostream &os);

    //Constructor
    Segment(std::string aName, Point point1, Point point2);

//Private attributes
private :
    Point pointA;
    Point pointB;
};


#endif //TP_CPP_5_SEGMENT_H
