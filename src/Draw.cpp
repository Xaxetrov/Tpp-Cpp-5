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

    int Draw::Move(string name, int dX, int dY)
    {
        map<string,Object>::iterator myObj = allObjects.find(name);

        if(myObj == allObjects.end())
        {
            // This object doesnt exists !
            return 1;
        }
        else
        {
            return myObj->second.Move(dX,dY);
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
        string name;
        string points;

        ss >> name;
        getline(ss,points);

        return AddSegment(name,points);
    }
    else if(cmdType=="R")
    {
        string name;
        string points;

        ss >> name;
        getline(ss,points);

        return AddRectangle(name,points);
    }
    else if(cmdType=="PC")
    {
        string name;
        string points;

        ss >> name;
        getline(ss,points);

        return AddPolygon(name,points);
    }
    else if(cmdType=="OR")
    {
        vector<string> toTreat;
        string nameX;
        while(ss>>nameX)
        {
            toTreat.push_back(nameX);
        }
        //Call Reunion method here
    }
    else if(cmdType=="OI")
    {
        vector<string> toTreat;
        string nameX;
        while(ss>>nameX)
        {
            toTreat.push_back(nameX);
        }
        //Call Intersection method here
    }
    else if(cmdType=="HIT")
    {
        string Name;
        int x, y;
        cin >> Name >> x >> y;
        //Call Hit test method here
    }
    else if(cmdType=="DELETE")
    {
        vector<string> toTreat;
        string nameX;
        while(ss>>nameX)
        {
            toTreat.push_back(nameX);
        }
        //Call Deletion method here
    }
    else if(cmdType=="MOVE")
    {
        {
            string Name;
            int dX, dY;
            cin >> Name >> dX >> dY;
            return Move(Name,dX,dY);
        }
    }
    else if(cmdType=="LIST")
    {
        List();
    }
    else if(cmdType=="UNDO")
    {
        //Call Undo method here
    }
    else if(cmdType == "REDO")
    {
        //Call Redo method here
    }
    else if(cmdType=="LOAD")
    {
        string filename;
        cin >> filename;
        //Call Load method here
    }
    else if(cmdType=="SAVE")
    {
        string filename;
        cin >> filename;
        //Call Save method here
    }
    else if(cmdType=="CLEAR")
    {
        //Call Clear method here
    }
    else if(cmdType=="EXIT")
    {
        exit(0);
    }
}
