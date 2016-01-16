//
// Created by Théo on 13/01/2016.
//

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
    int ExecuteCommand(string cmdStr);
    void printResult(string cmdType, int returncode);

    int AddSegment(string name, string points);
    int AddPolygon(string name, string points);
    int AddRectangle(string name, string points);
    int Delete(string names);
    void List();
    int Move(string object, int dX, int dY);
    int Clear();
    int Save(string filename);
    int Load(string filename);
    int Undo();
    int Redo();

    //Constructor
    Draw();

protected:
    map<string,Object*> allObjects;
    list<string> historic;
    list<string> reverseHistoric;
    int historicPosition;

};

#endif //TP_CPP_5_DRAW_H
