/***********************************************************************************************************************
    Object  -  realisation
    ----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/


#include "Object.h"
#include <iostream>

const bool Object::Hits(Point aPoint) {
    std::cerr << "Object virtual method called";
    return false;
}

int Object::Move(int dX, int dY) {
    std::cerr << "Object virtual move method called";
    return 0;
}

std::string Object::toString()
{
    std::cerr << "Object virtual method called";
    return "";
}

int Object::GetCommand(std::ostream &os)
{
    os << "ERROR Object virtual";
    return 1;
}

Object::Object(std::string aName) : name(aName)
{

}
