//
// Created by Théo on 13/01/2016.
//

#include "Draw.h"
#include "Segment.h"
#include "Polygon.h"
#include "Rectangle.h"
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

    int Draw::AddPolygon(string name,string points)
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

            if(myCoords.size() % 2 == 0)
            {
                int size = myCoords.size();
                for(int i=0; i< size-3; i+=2)
                {
                    if(myCoords[i] == myCoords[size-2] && myCoords[i+1] == myCoords[size-1])
                    {
                        // You passed the same point two times
                        return 4;
                    }
                }

                if(size >= 6)
                {
                    Point A(myCoords[size-6],myCoords[size-5]);
                    Point B(myCoords[size-4],myCoords[size-3]);
                    Point C(myCoords[size-2],myCoords[size-1]);

                    Segment AB("AB",A,B);
                    Segment BC("BC",B,C);

                    if(AB.Angle(BC) > 90)
                    {
                        // The polynom is not convex.
                        return 3;
                    }
                }
            }
        }

        int finalSize = myCoords.size();
        if(finalSize < 6 || finalSize%2 != 0)
        {
            // A Polygon is defined by at least three points.
            return 2;
        }

        // Test if the closing segment of the polygon is not making it not convex
        Point A(myCoords[finalSize-4],myCoords[finalSize-3]);
        Point B(myCoords[finalSize-2],myCoords[finalSize-1]);
        Point C(myCoords[0],myCoords[1]);
        Point D(myCoords[2],myCoords[3]);

        Segment AB("AB",A,B);
        Segment BC("BC",B,C);
        Segment CD("CD",C,D);

        if(AB.Angle(BC) > 90 || BC.Angle(CD) > 90)
        {
            // The polynom is not convex.
            return 3;
        }

        //pair<map<string,Object>::iterator,bool> o = allObjects.insert(make_pair(name,Polygon(name)));

        for(int i = 0; i < finalSize; i+=2)
        {
            //myPoly->second.Add(Point(myCoords[i],myCoords[i+1]));  //TODO: Find a way to add points in Polygon ...
        }

        historic.push_front("P "+name+" "+points);
        reverseHistoric.push_front("DELETE "+name);

        return 0;
    }

    int Draw::AddRectangle(string name, string points)
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
            // A Rectangle is defined by only two points.
            return 2;
        }

        if(myCoords[0] > myCoords[2] || myCoords[1] < myCoords[3])
        {
            // Your points arent corrects. I mean its not top-left and bottom-right points.
            return 2;
        }

        allObjects.insert(make_pair(name,Rectangle(name))); //TODO : Think about how we can add points.
        historic.push_front("R "+name+" "+points);
        reverseHistoric.push_front("DELETE "+name);

        return 0;
    }

    void Draw::List()
    {
        map<string,Object>::iterator i;
        for(i = allObjects.begin();i!=allObjects.end();i++)
        {
            cout << (*i).second.toString() << endl;
        }
    }

//Constructors
    Draw::Draw() : historicPosition(0)
    {}

int Draw::ExecuteCommand(string cmdStr) {
    stringstream ss(cmdStr);

    string cmdType;
    ss >> cmdType;
    if(cmdType=="S")
    {
        int x1,x2;
        ss >> x1;
        ss >> x2;
        //Call Segment creation method here
    }
    else if(cmdType=="R")
    {
        int x1,x2;
        ss >> x1;
        ss >> x2;
        //Call Rectangle creation method here
    }
    else if(cmdType=="PC")
    {
        vector<int> pts;
        int ptI;
        while(ss>>ptI)
        {
            pts.push_back(ptI);
        }
    }
    else if(cmdType=="OR")
    {

    }
    else if(cmdType=="OI")
    {

    }
    else if(cmdType=="HIT")
    {

    }
    else if(cmdType=="DELETE")
    {

    }
    else if(cmdType=="MOVE")
    {

    }
    else if(cmdType=="LIST")
    {

    }
    else if(cmdType=="UNDO")
    {

    }
    else if(cmdType == "REDO")
    {

    }
    else if(cmdType=="LOAD")
    {

    }
    else if(cmdType=="SAVE")
    {

    }
    else if(cmdType=="CLEAR")
    {

    }
}
