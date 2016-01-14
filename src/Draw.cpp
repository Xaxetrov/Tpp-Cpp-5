//
// Created by Théo on 13/01/2016.
//

#include "Draw.h"
#include "Segment.h"
#include <vector>
#include <sstream>

//Public methods
    int Draw::AddSegment(string name,string points)
    {
        if(allObjects.find(name) != allObjects.end())
        {
            // This object name already exists !
            return 1;
        }

        int pos=0;
        int toPos;
        vector<int> myCoords;

        istringstream myStream(points);
        while(!myStream.eof())
        {
            int tempI;
            if(myStream >> tempI)
            {
                myCoords.push_back(tempI);
            }
            else
            {
                // The entered number is not really a number ...
                return 2;
            }
        }

        if(myCoords.size() != 4)
        {
            // A Segment is defined by only two points.
            return 2;
        }

        allObjects.insert(make_pair(name,Segment(name,Point(myCoords[0],myCoords[1]),Point(myCoords[2],myCoords[3]))));
        historic.push_front("S "+name+" "+points);
        reverseHistoric.push_front("DELETE "+name);

        return 0;
    }

//Constructors
    Draw::Draw() : historicPosition(0)
    {}