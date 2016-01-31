/***********************************************************************************************************************
    Object  -  description
    ----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

//------------------------------------------------------------------------------------------------------------- Includes
// Personal includes
#include "Point.h"
// System includes
#include <string>
#include <iostream>
#include <algorithm>
#include <iostream>

#ifndef TP_CPP_5_OBJECT_H
#define TP_CPP_5_OBJECT_H

//----------------------------------------------------------------------------------------------------------------------
// The Object class purpose is to define generic attributes and parameters of an Object
// It is the abstract class which is inherited by all forms in a Draw
//----------------------------------------------------------------------------------------------------------------------
class Object
{
//--------------------------------------------------------------------------------------------------------------- Public
// Public methods
public :
    //Inline getter
    const std::string& GetName() {return name;}

    //Public abstract methods
    virtual const bool Hits(Point aPoint)=0;
    // Manual :
    // Pure abstract method used to check if a point is "in" an object

    virtual int Move(int dX, int dY)=0;
    // Manual :
    // Pure abstract method used to move an object by dX and dY

    virtual std::string toString();
    // Manual :
    // Abstract method used to print Object information

    virtual int GetCommand(std::ostream &os)=0;
    // Manual :
    // Pure abstract method used to get the command that can create the instantiated Object

    virtual Object * Clone();
    // Manual :
    // Return a pointer on a copy of the object

    //Public constructor
    Object(std::string aName);

//Protected attribute
protected:
    std::string name;
    // The name of an Object
};


#endif //TP_CPP_5_OBJECT_H
