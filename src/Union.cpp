/***********************************************************************************************************************
    Union  -  realisation
    -----------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

// ------------------------------------------------------------------------------------------------------------ INCLUDES
// Personal includes
#include "Union.h"
// System includes
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
    toReturn << " objects";

    string result;
    getline(toReturn,result);
    return result;
}

int Union::GetCommand(ostream &os,string newName)
{
    if(newName == "")
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
        //string currentName = (*i)->GetName();
        nameLine+= " " + tmpName;
    }
    os << "\n" << "OR " << newName << nameLine;
    os << "\n" << "DELETE" << nameLine;
    return 0;
}

Object * Union::Clone()
{
    Object *ptr = new Union(*this);
    return ptr;
}
