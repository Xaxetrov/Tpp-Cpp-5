//
// Created by Théo on 29/01/2016.
//

#ifndef TP_CPP_5_UNION_H
#define TP_CPP_5_UNION_H

// ------------------------------------------------------------------------------------------------------------ INCLUDES
// Personal includes
#include "MultiObject.h"
// System includes
#include <string>
#include <list>
#include <iostream>
using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// The class Union represents an union of few objects
// ---------------------------------------------------------------------------------------------------------------------

class Union : public MultiObject
{

public:
    // ---------------------------------------------------------------------------------------------------------- PUBLIC
    // Public methods
    const bool Hits(Point aPoint);
    // This method return true if the point hits any object of the multiobject union

    string toString();
    // This method give a representation of the union in a string

    int GetCommand(ostream &os,string newName="");
    // This method give the command that permits to make the union with potentially a new name

    Object * Clone();
    // This method returns a pointer on a copy of the union

    // Constructor(s)
    Union(string name, list<Object *> objectsToUse);
    Union(Union &toCopy);
    virtual ~Union();

};


#endif //TP_CPP_5_UNION_H
