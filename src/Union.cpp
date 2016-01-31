//
// Created by Théo on 29/01/2016.
//

// ------------------------------------------------------------------------------------------------------------ INCLUDES
// Personal includes
#include "Union.h"
// System includes
#include <string>
#include <list>
#include <iostream>
#include <sstream>
using namespace std;

// ------------------------------------------------------------------------------------------------------ CONSTRUCTOR(S)
Union::Union(string name, list<Object*> objectsToUse)
        : MultiObject(name,objectsToUse)
{

}

Union::Union(Union &toCopy)
        : MultiObject(toCopy)
{

}

Union::~Union()
{

}

// ------------------------------------------------------------------------------------------------------------- METHODS
const bool Union::Hits(Point aPoint)
{
    bool result=false;
    list<Object *>::iterator i;

    for(i=composingObjects.begin(); i != composingObjects.end(); i++)
    {
        // If one of the object of the union is hit, the union is hitten !
        if((*i)->Hits(aPoint))
        {
            result=true;
        }
    }

    return result;
}

string Union::toString()
{
    stringstream toReturn;
    toReturn << "Union named ";
    toReturn << name;
    toReturn << " from ";
    toReturn << composingObjects.size();
    toReturn << " objects.";

    string result;
    getline(toReturn,result);
    return result;
}

int Union::GetCommand(ostream &os)
{
    return 0; //TODO : This.
}

Object * Union::Clone()
{
    Object *ptr = new Union(*this);
    return ptr;
}
