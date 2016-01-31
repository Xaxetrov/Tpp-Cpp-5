//
// Created by Théo on 29/01/2016.
//

// ------------------------------------------------------------------------------------------------------------ INCLUDES
// Personal includes
#include "MultiObject.h"
// System includes
#include <string>
#include <list>
#include <iostream>
#include <sstream>
using namespace std;

// ------------------------------------------------------------------------------------------------------ CONSTRUCTOR(S)
MultiObject::MultiObject(string aName, list<Object *> objectsToUse)
    : Object(aName)
{
    list<Object *>::iterator i;
    for(i = objectsToUse.begin(); i != objectsToUse.end(); i++)
    {
        composingObjects.push_back(*i);
    }
}

MultiObject::MultiObject(MultiObject &toCopy)
    : Object(toCopy.name)
{
    list<Object *>::iterator i;
    for(i = toCopy.composingObjects.begin();i != toCopy.composingObjects.end(); i++)
    {
        Object *obj = (*i)->Clone();
        composingObjects.push_back(obj);
    }
}

MultiObject::~MultiObject()
{
    list<Object *>::iterator i;
    for(i = composingObjects.begin(); i != composingObjects.end(); i++)
    {
        delete *i;
    }
}

// ------------------------------------------------------------------------------------------------------------- METHODS
string MultiObject::toString()
{
    stringstream toReturn;
    toReturn << "Composed object named ";
    toReturn << name;
    toReturn << " from ";
    toReturn << composingObjects.size();
    toReturn << " objects.";

    string result;
    getline(toReturn,result);
    return result;
}

const bool MultiObject::Hits(Point aPoint)
{
    return false;
}

int MultiObject::Move(int dX, int dY)
{
    list<Object *>::iterator i;
    int result = 0;

    for(i=composingObjects.begin();i != composingObjects.end();i++)
    {
        if(!((*i)->Move(dX,dY)))
        {
            result=3;
        }
    }

    return result;
}

int MultiObject::GetCommand(ostream &os)
{
    return 0;
}

Object * Object::Clone()
{
    cerr << "You are trying to clone an abstract multiobject ..." << endl;
    return this;
}