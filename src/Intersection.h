//
// Created by Théo on 29/01/2016.
//

#ifndef TP_CPP_5_INTERSECTION_H
#define TP_CPP_5_INTERSECTION_H

// ------------------------------------------------------------------------------------------------------------ INCLUDES
// Personal includes
#include "MultiObject.h"
// System includes
#include <string>
#include <iostream>
#include <list>
using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// The class Intersection represents an intersection of few objects
// ---------------------------------------------------------------------------------------------------------------------

class Intersection : public MultiObject
{

public:
    // ---------------------------------------------------------------------------------------------------------- PUBLIC
    const bool Hits(Point aPoint);
    // This method return true if the point hits all objects of the multiobject intersection

    string toString();
    // This method give a representation of the intersection in a string

    int GetCommand(ostream &os,string newName="");
    // This method give the command that permits to make the intersection with potentially a new name

    Object * Clone();
    // This method returns a pointer on a copy of the intersection

    // Constructor(s)
    Intersection(string name, list<Object *> objectsToUse);
    Intersection(Intersection &toCopy);
    virtual ~Intersection();

};


#endif //TP_CPP_5_INTERSECTION_H
