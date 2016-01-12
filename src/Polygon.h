//
// Created by Edern Haumont on 11/01/2016.
//

#ifndef TP_CPP_5_POLYGON_H
#define TP_CPP_5_POLYGON_H

#include "Object.h"

class Polygon : public Object{

//Public methods
public :

    //Public methods
    const bool Hits(Point aPoint);
    int Move(int dX, int dY);

    //Constructor
    Polygon(const std::string aName); //TODO : What if there is less than 3 points ?

//Protected attributes
protected :
    std::vector<Point> points;
};


#endif //TP_CPP_5_POLYGON_H
