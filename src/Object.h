//
// Created by Edern Haumont on 11/01/2016.
//
#include <string>
#include <iostream>
#include <algorithm>
#include "Point.h"

#ifndef TP_CPP_5_OBJECT_H
#define TP_CPP_5_OBJECT_H


class Object {

public :
    //Inline getter
    const std::string& GetName() {return name;}

    //Public abstract methods
    virtual const bool Hits(Point aPoint);
    virtual int Move(int dX, int dY)=0;
    virtual std::string toString();

    //Public constructor
    Object(std::string aName);

//Protected attribute
protected:
    std::string name;
};


#endif //TP_CPP_5_OBJECT_H
