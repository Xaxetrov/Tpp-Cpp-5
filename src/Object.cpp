//
// Created by Edern Haumont on 11/01/2016.
//


#include "Object.h"

const bool Object::Hits(Point aPoint) {
    std::cerr << "Object virtual method called";
    return false;
}

int Object::Move(int dX, int dY) {
    std::cerr << "Object virtual method called";
    return 0;
}

Object::Object(std::string aName) : name(aName)
{

}
