/***********************************************************************************************************************
    Rectangle  -  description
    -------------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#ifndef TP_CPP_5_RECTANGLE_H
#define TP_CPP_5_RECTANGLE_H

//------------------------------------------------------------------------------------------------------------- Includes
// Personal includes
#include "Polygon.h"

//----------------------------------------------------------------------------------------------------------------------
// The Rectangle class represents a convex rectangle defined by its top-left and bottom-right points
// A Rectangle is a Polygon
//----------------------------------------------------------------------------------------------------------------------
class Rectangle : public Polygon{

//--------------------------------------------------------------------------------------------------------------- Public
public :

    // Public methods
    const bool Hits(Point aPoint);
    // Manual :
    // Checks if a point given in parameter is in the Rectangle

    std::string toString();
    // Manual :
    // Method used to print Rectangle  information (name)

    int GetCommand(std::ostream &os);
    // Manual :
    // Method used to get the command that can create the instantiated Rectangle

    // Constructor
    Rectangle(const std::string aName, std::vector<int> &myCoords); //TODO : What if there is less than 3 points ?

    // Destructor
    virtual ~Rectangle();
};


#endif //TP_CPP_5_RECTANGLE_H
