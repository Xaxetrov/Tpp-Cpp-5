/***********************************************************************************************************************
    Intersection  -  realisation
    -----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

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
    bool result=false;
    list<Object *>::iterator i;

    for(i=composingObjects.begin(); i != composingObjects.end(); i++)
    {
        // If one of the object of the intesection isn't hit, the intersection is not hitten !
        if(((*i)->Hits(aPoint)))
        {
            result=true;
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
    toReturn << " objects";

    string result;
    getline(toReturn,result);
    return result;
}

int Intersection::GetCommand(ostream &os,string newName)
{
    if(newName=="")
    {
        newName = name;
    }

    string nameLine ="";
    os << "MULT" << composingObjects.size()+2;
    list<Object *>::iterator i;
    for (i=composingObjects.begin();i != composingObjects.end();i++)
    {
        //Temporary name to avoid double with original object
        string tmpName = "tmpObjectForMultiConstruction";
        tmpName += name;
        tmpName += "From";
        tmpName += (*i)->GetName();;

        os << "\n";
        (*i)->GetCommand(os,tmpName);
        nameLine+= " " + tmpName;
    }
    os << "\n" << "OI " << newName << nameLine;
    os << "\n" << "DELETE" << nameLine;
    return 0;
}

Object * Intersection::Clone()
{
    Object *ptr = new Intersection(*this);
    return ptr;
}

