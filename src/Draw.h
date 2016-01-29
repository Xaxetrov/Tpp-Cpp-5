/***********************************************************************************************************************
    Draw  -  description
    --------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#ifndef TP_CPP_5_DRAW_H
#define TP_CPP_5_DRAW_H

#include "Rectangle.h"
#include <string>
#include <map>
#include <list>
using namespace std;

class Draw
{

//Public methods
public:
    int ExecuteCommand(string cmdStr, bool notInHistoric = false);
    void printResult(string cmdType, int returncode);

    int AddSegment(string name, string points, bool notInHistoric = false);
    int AddPolygon(string name, string points, bool notInHistoric = false);
    int AddRectangle(string name, string points, bool notInHistoric = false);
    int Delete(string names, bool notInHistoric = false);
    void List();
    int Move(string object, int dX, int dY);
    int Clear();
    int Save(string filename);
    int Load(string filename);
    int Undo();
    int Redo();
    int Hit(string name, int x, int y);

    //Constructor
    Draw();

protected:
    map<string,Object*> allObjects;
    list<string> historic;
    list<string> reverseHistoric;
    int historicPosition;

};

#endif //TP_CPP_5_DRAW_H
