//
// Created by Edern Haumont on 11/01/2016.
//

#ifndef TP_CPP_5_RECTANGLE_H
#define TP_CPP_5_RECTANGLE_H

#include "Polygon.h"
#include <vector>
#include <string>

class Rectangle : public Polygon{

//Public methods
public :

    //Public methods
    const bool Hits(Point aPoint);
    virtual int Move(int dX,int dY); //TODO : Do we really need to exactly copy the Move method of Polygon in Rectangle ?
    std::string toString();

    //Constructor
    Rectangle(const std::string aName); //TODO : What if there is less than 3 points ?
    virtual ~Rectangle();

//Protected attributes
protected :

};


#endif //TP_CPP_5_RECTANGLE_H
