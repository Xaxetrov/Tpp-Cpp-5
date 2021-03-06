/***********************************************************************************************************************
    Polygon  -  description
    -----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/
#ifndef TP_CPP_5_POLYGON_H
#define TP_CPP_5_POLYGON_H

//------------------------------------------------------------------------------------------------------------- INCLUDES
// Personal includes
#include "Object.h"
#include "Point.h"
// System includes
#include <vector>
using namespace std;

//----------------------------------------------------------------------------------------------------------------------
// The Polygon class represents a convex polygon defined by its points
// A Polygon is an Object
//----------------------------------------------------------------------------------------------------------------------
class Polygon : public Object{

//--------------------------------------------------------------------------------------------------------------- PUBLIC
public :

    // Public methods
    virtual const bool Hits(Point aPoint);
    // Manual :
    // Checks if a point given in parameter is in the Polygon

    virtual int Move(int dX, int dY);
    // Manual :
    // Moves the Polygon position by dX and dY

    string toString();
    // Manual :
    // Method used to print Polygon information (name)

    virtual int GetCommand(ostream &os,string newName="");
    // Manual :
    // Method used to get the command that can create the instantiated Polygon with potentially a new name

    virtual Object * Clone();
    // Manual :
    // This method return a pointer on a copy of the Polygon

    // Constructor(s)
    Polygon(const string aName,vector<int> &myCoords);
    // Manual :
    // Creates a polygon and initialize its list of points with another given in parameter

    Polygon(Polygon &toCopy);
    // Manual:
    // Create a new Polygon by coping an other.

    // Destructor
    virtual ~Polygon();


//------------------------------------------------------------------------------------------------------------ PROTECTED
protected :
    // Protected Methods
    int Add(Point &aPoint);
    // Manual :
    // Adds a point to the polygon

    //Protected Attribute
    vector<Point> points;
    // The list of the points that define the polygon
};


#endif //TP_CPP_5_POLYGON_H
