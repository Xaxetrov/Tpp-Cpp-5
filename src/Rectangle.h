/***********************************************************************************************************************
    Rectangle  -  description
    -------------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#ifndef TP_CPP_5_RECTANGLE_H
#define TP_CPP_5_RECTANGLE_H

#include "Polygon.h"
#include <vector>
#include <string>
#include <iostream>

class Rectangle : public Polygon{

//Public methods
public :

    //Public methods
    const bool Hits(Point aPoint);
    std::string toString();
    int GetCommand(std::ostream &os);

    //Constructor
    Rectangle(const std::string aName, std::vector<int> &myCoords); //TODO : What if there is less than 3 points ?
    virtual ~Rectangle();

//Protected attributes
protected :

};


#endif //TP_CPP_5_RECTANGLE_H
