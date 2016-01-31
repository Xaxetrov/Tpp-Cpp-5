/***********************************************************************************************************************
    Segment  -  description
    -----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#ifndef TP_CPP_5_SEGMENT_H
#define TP_CPP_5_SEGMENT_H

//------------------------------------------------------------------------------------------------------------- Includes
// Personal includes
#include "Object.h"
#include "Point.h"

//------------------------------------------------------------------------------------------------------------ Constants
static const double EPSILON = 0.1;

//----------------------------------------------------------------------------------------------------------------------
// The Segment class represents a segment defined by its two points
// A Segment is an Object
//----------------------------------------------------------------------------------------------------------------------
class Segment : public Object{

//--------------------------------------------------------------------------------------------------------------- Public
public :

    // Inline getters and setters
    const Point& GetPointA() {return pointA;}
    const Point& GetPointB() {return pointB;}

    // Public methods
    const bool Hits(Point aPoint);
    // Manual :
    // Checks if a point given in parameter is on the segment with a precision of EPSILON

    virtual int Move(int dX, int dY);
    // Manual :
    // Moves the segment position by dX and dY

    int Angle(Segment othSeg);
    // Manual :
    // Returns the angle between this segment and another one given in parameter

    std::string toString();
    // Manual :
    // Method used to print Segment information (name)

    int GetCommand(std::ostream &os);
    // Manual :
    // Method used to get the command that can create the instantiated Segment

    //Constructor
    Segment(std::string aName, Point point1, Point point2);
    Segment(Segment &toCopy);

//-------------------------------------------------------------------------------------------------------------- Private
//Private attributes
private :
    Point pointA;
    Point pointB;
};


#endif //TP_CPP_5_SEGMENT_H
