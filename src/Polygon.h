/***********************************************************************************************************************
    Polygon  -  description
    -----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/
#ifndef TP_CPP_5_POLYGON_H
#define TP_CPP_5_POLYGON_H

//------------------------------------------------------------------------------------------------------------- Includes
// Personal includes
#include "Object.h"
#include "Point.h"
// System includes
#include <vector>

//----------------------------------------------------------------------------------------------------------------------
// The Polygon class represents a convex polygon defined by its points
// A Polygon is an Object
//----------------------------------------------------------------------------------------------------------------------
class Polygon : public Object{

//--------------------------------------------------------------------------------------------------------------- Public
public :

    // Public methods
    virtual const bool Hits(Point aPoint);
    // Manual :
    // Checks if a point given in parameter is in the Polygon

    virtual int Move(int dX, int dY);
    // Manual :
    // Moves the Polygon position by dX and dY

    std::string toString();
    // Manual :
    // Method used to print Polygon information (name)

    virtual int GetCommand(std::ostream &os);
    // Manual :
    // Method used to get the command that can create the instantiated Polygon

    // Constructor
    Polygon(const std::string aName,std::vector<int> &myCoords);
    // Manual :
    // Creates a polygon and initialize its list of points with another given in parameter

    Polygon(Polygon &toCopy);
    // Manual:
    // Create a new Polygon by coping an other.

    // Destructor
    virtual ~Polygon();

    friend int main();

//------------------------------------------------------------------------------------------------------------ Protected
protected :
    // Protected Methods
    int Add(Point aPoint);
    // Manual :
    // Adds a point to the polygon

    //Protected Attribute
    std::vector<Point> points;
    // The list of the points that define the polygon
};


#endif //TP_CPP_5_POLYGON_H
