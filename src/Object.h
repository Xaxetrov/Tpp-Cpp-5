//
// Created by Edern Haumont on 11/01/2016.
//
#include <string>
#include <iostream>
#include <algorithm>
#include "Point.h"
#include <iostream>

#ifndef TP_CPP_5_OBJECT_H
#define TP_CPP_5_OBJECT_H


class Object {

public :
    //Inline getter
    const std::string& GetName() {return name;}

    //Public abstract methods
    virtual const bool Hits(Point aPoint)=0;
    virtual int Move(int dX, int dY)=0;
    virtual std::string toString();
    virtual int GetCommand(std::iostream &ios);

    //Public constructor
    Object(std::string aName);

//Protected attribute
protected:
    std::string name;
};


#endif //TP_CPP_5_OBJECT_H
