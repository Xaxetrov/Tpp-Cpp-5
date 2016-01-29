/***********************************************************************************************************************
    Polygon  -  description
    -----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/
#ifndef TP_CPP_5_POLYGON_H
#define TP_CPP_5_POLYGON_H

#include "Object.h"
#include "Point.h"
#include <vector>
#include <string>
#include <iostream>

class Polygon : public Object{

//Public methods
public :

    //Public methods
    virtual const bool Hits(Point aPoint);
    virtual int Move(int dX, int dY);
    std::string toString();
    int GetCommand(std::ostream &os);

    //Constructor
    Polygon(const std::string aName,std::vector<int> &myCoords);
    virtual ~Polygon();

protected :
    //Protected Methods
    int Add(Point aPoint);

    //Protected Attribute
    std::vector<Point> points;
};


#endif //TP_CPP_5_POLYGON_H
