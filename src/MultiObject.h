//
// Created by Théo on 29/01/2016.
//

#ifndef TP_CPP_5_MULTIOBJECT_H
#define TP_CPP_5_MULTIOBJECT_H

// ------------------------------------------------------------------------------------------------------------ Includes
// Personal includes
#include "Object.h"
// System includes
#include <string>
#include <list>
#include <iostream>
using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// The class Multiobject represent an object which have been made by an union or an intersection
// ---------------------------------------------------------------------------------------------------------------------

class MultiObject : public Object
{

public:
    // ---------------------------------------------------------------------------------------------------------- PUBLIC
    // Public methods

    virtual const bool Hits(Point aPoint)=0;
    // This method return true if the point hits the multiobject

    virtual int Move(int dX, int dY);
    // This method will move the multiobject by the vector enter in parameters

    virtual string toString();
    // This method give a representation of the multiobject in a string

    virtual int GetCommand(ostream &os)=0;
    // This method give the command that permits to make the multiobject

    virtual Object * Clone();
    // This method returns a pointer on a copy of the multiobject

    //Constructor(s)
    MultiObject(string aName, list<Object *> objectsToUse);
    // This constructor create a multiobject based on other objects.

    MultiObject(MultiObject &toCopy);
    // This constructor make a copy of an other multiobject

    virtual ~MultiObject();
    // Destructor of a MultiObject

    // ------------------------------------------------------------------------------------------------------- PROTECTED
    // Attributes
    list<Object *> composingObjects;

};

#endif //TP_CPP_5_MULTIOBJECT_H
