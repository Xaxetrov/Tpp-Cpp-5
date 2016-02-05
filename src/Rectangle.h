/***********************************************************************************************************************
    Rectangle  -  description
    -------------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#ifndef TP_CPP_5_RECTANGLE_H
#define TP_CPP_5_RECTANGLE_H

//------------------------------------------------------------------------------------------------------------- INCLUDES
// Personal includes
#include "Polygon.h"
using namespace std;

//----------------------------------------------------------------------------------------------------------------------
// The Rectangle class represents a convex rectangle defined by its top-left and bottom-right points
// A Rectangle is a Polygon
//----------------------------------------------------------------------------------------------------------------------

class Rectangle : public Polygon{
//--------------------------------------------------------------------------------------------------------------- PUBLIC
public :

    // Public methods
    const bool Hits(Point aPoint);
    // Manual :
    // Checks if a point given in parameter is in the Rectangle

    string toString();
    // Manual :
    // Method used to print Rectangle  information (name)

    int GetCommand(ostream &os,string newName="");
    // Manual :
    // Method used to get the command that can create the instantiated Rectangle with potentially a new name

    Object * Clone();
    // Manual :
    // Returns a pointer on a copy of the Rectangle

    // Constructor
    Rectangle(const string aName, vector<int> &myCoords);
    Rectangle(Rectangle &toCopy);

    // Destructor
    virtual ~Rectangle();
};


#endif //TP_CPP_5_RECTANGLE_H
