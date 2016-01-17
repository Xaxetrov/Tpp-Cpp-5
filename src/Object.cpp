//
// Created by Edern Haumont on 11/01/2016.
//


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

int Object::GetCommand(std::iostream &ios)
{
    ios << "ERROR Object virtual";
    return 1;
}

Object::Object(std::string aName) : name(aName)
{

}
