//
// Created by Théo on 29/01/2016.
//

// ------------------------------------------------------------------------------------------------------------ INCLUDES
// Personal includes
#include "Intersection.h"
// System includes
#include <string>
#include <list>
#include <iostream>
#include <sstream>
using namespace std;

// ------------------------------------------------------------------------------------------------------ CONSTRUCTOR(S)
Intersection::Intersection(string name, list<Object*> objectsToUse)
        : MultiObject(name,objectsToUse)
{

}

Intersection::Intersection(Intersection &toCopy)
        : MultiObject(toCopy)
{

}

Intersection::~Intersection()
{

}

// ------------------------------------------------------------------------------------------------------------- METHODS
const bool Intersection::Hits(Point aPoint)
{
    bool result=true;
    list<Object *>::iterator i;

    for(i=composingObjects.begin(); i != composingObjects.end(); i++)
    {
        // If one of the object of the intesection isn't hit, the intersection is not hitten !
        if(!((*i)->Hits(aPoint)))
        {
            result=false;
        }
    }

    return result;
}

string Intersection::toString()
{
    stringstream toReturn;
    toReturn << "Intersection named ";
    toReturn << name;
    toReturn << " from ";
    toReturn << composingObjects.size();
    toReturn << " objects.";

    string result;
    getline(toReturn,result);
    return result;
}

int Intersection::GetCommand(ostream &os)
{
    string nameLine ="";
    os << "MULT" << composingObjects.size()+2;
    list<Object *>::iterator i;
    for (i=composingObjects.begin();i != composingObjects.end();i++)
    {
        os << "\n";
        (*i)->GetCommand(os);
        string currentName = (*i)->GetName();
        nameLine+= " " + currentName;
    }
    os << "\n" << "OI" << nameLine;
    os << "\n" << "DELETE" << nameLine;
}

Object * Intersection::Clone()
{
    Object *ptr = new Intersection(*this);
    return ptr;
}

