/***********************************************************************************************************************
    Point  -  realisation
    ---------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#include "Point.h"

// Public Methods
void Point::Move(int dX, int dY)
{
    x+=dX;
    y+=dY;
}

// Constructors
Point::Point(int myX, int myY) : x(myX), y(myY)
{

}

Point::~Point() {

}
