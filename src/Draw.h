/***********************************************************************************************************************
    Draw  -  description
    --------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#ifndef TP_CPP_5_DRAW_H
#define TP_CPP_5_DRAW_H

//------------------------------------------------------------------------------------------------------------- Includes
// Personal includes
#include "Rectangle.h"
#include "Segment.h"
#include "Intersection.h"
#include "Union.h"
// System includes
#include <string>
#include <map>
#include <list>
using namespace std;

//----------------------------------------------------------------------------------------------------------------------
// The class Draw handles the interpretation and the execution call of commands
// It represents the application draw
//----------------------------------------------------------------------------------------------------------------------
class Draw
{
//--------------------------------------------------------------------------------------------------------------- Public
// Public methods
public :
    int ExecuteCommand(string cmdStr, bool notInHistoric = false);
    // Manual :
    // Executes a command contained in cmdStr
    // If notInHistoric is true, does not add the command to the historic

    //Constructor
    Draw();
//-------------------------------------------------------------------------------------------------------------- Private
// Private methods
private :
    void printResult(string cmdType, int returncode);
    // Manual :
    // Prints the result of the execution of a command, depending on the returncode
    // Contract :
    //

    int AddSegment(string name, string points, bool notInHistoric = false);
    // Manual :
    // Adds a segment to the draw

    int AddPolygon(string name, string points, bool notInHistoric = false);
    // Manual :
    // Adds a polygon to the draw

    int AddRectangle(string name, string points, bool notInHistoric = false);
    // Manual :
    // Adds a rectangle to the draw

    int AddIntersection(string name, string others, bool notInHistoric = false);
    // Manual :
    // Adds an object by intersection of others

    int AddReunion(string name, string others, bool notInHistoric = false);
    // Manual :
    // Adds an object by reunion of others

    int Delete(string names, bool notInHistoric = false);
    // Manual :
    // Deletes one or several objects of the draw

    void List();
    // Manual :
    // Prints all objects of the draw

    int Move(string object, int dX, int dY);
    // Manual :
    // Moves one object of dX and dY

    int Clear();
    // Manual :
    // Clears all objects of the draw

    int Save(string filename);
    // Manual :
    // Saves all objects of the draw in a file named with filename

    int Load(string filename);
    // Manual :
    // Add all objects of named with filename to the draw

    int Undo();
    // Manual :
    // Undo last action

    int Redo();
    // Manual :
    // Redo last undid action

    int Hit(string name, int x, int y);
    // Manual :
    // Prints whether the point given by x and y is in an object identified by its name

// Private attributes
private:
    map<string,Object*> allObjects;
    // All of our objects currently in the draw
    // Stored in a map for performance
    // Contract :
    // Behavior is not guaranteed if you insert an object with a name that already exists in the map

    list<string> historic;
    // The historic of actions

    list<string> reverseHistoric;
    // The historic of opposite actions to the historic

    int historicPosition;
    // The current position in the historic

};

#endif //TP_CPP_5_DRAW_H
