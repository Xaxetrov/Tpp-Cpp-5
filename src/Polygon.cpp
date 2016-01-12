//
// Created by Edern Haumont on 11/01/2016.
//

#include "Polygon.h"


Polygon::Polygon(const std::string aName) : Object(aName)
{

}

const bool Polygon::Hits(Point aPoint) {
    return Object::Hits(aPoint);
}

int Polygon::Move(int dX, int dY) {
    return Object::Move(dX, dY);
}
