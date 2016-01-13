//
// Created by Théo on 13/01/2016.
//

#include "Draw.h"
#include "Segment.h"
#include <vector>

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

        while(string::npos!=points.find(' ',pos))
        {
            toPos = points.find(' ',pos);
            myCoords.push_back(atoi(points.substr(pos,toPos).c_str()));
            pos = toPos+1;
        }
        myCoords.push_back(atoi(points.substr(pos).c_str()));

        if(myCoords.size() != 4)
        {
            // A Rectangle is defined by only two points.
            return 2;
        }

        if(myCoords[2] < myCoords[0] || myCoords[3] > myCoords[1])
        {
            // Points haven't correct value. I mean you mixed top-left point and bottom-right point.
            return 2;
        }

        allObjects.insert(make_pair(name,Segment(name,Point(myCoords[0],myCoords[1]),Point(myCoords[2],myCoords[3]))));
        historic.push_front("R "+name+" "+points);
        reverseHistoric.push_front("DELETE "+name);

        return 0;
    }

//Constructors
    Draw::Draw() : historicPosition(0)
    {}