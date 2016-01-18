//
// Created by Edern Haumont on 11/01/2016.
//

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
