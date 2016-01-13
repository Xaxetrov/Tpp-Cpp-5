//
// Created by Edern Haumont on 12/01/2016.
//

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