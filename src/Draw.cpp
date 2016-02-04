/***********************************************************************************************************************
    Draw  -  realisation
    --------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#include "Draw.h"
#include <fstream>

//Public methods
    int Draw::AddSegment(string name, string points, bool notInHistoric)
    {
        if(allObjects.find(name) != allObjects.end())
        {
            // This object name already exists !
            return 1;
        }

        vector<int> myCoords;

        stringstream myStream;
        myStream << points;

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
        allObjects.insert(make_pair(name,new Segment(name,Point(myCoords[0],myCoords[1]),Point(myCoords[2],myCoords[3]))));

        if(!notInHistoric)
        {
            historic.push_front("S "+name+" "+points);
            reverseHistoric.push_front("DELETE "+name);
        }

        return 0;
    }

    int Draw::AddPolygon(string name, string points, bool notInHistoric)
    {
        if(allObjects.find(name) != allObjects.end())
        {
            // This object name already exists !
            return 1;
        }

        vector<int> myCoords;
        int direction = -1;

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
                unsigned long size = myCoords.size();
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

                    int angle=AB.Angle(BC);
                    //cerr << angle << endl;

                    if(direction == -1 && angle != 0 && angle != 180)
                    {
                        //Detect the direction of all vectors in the polygon
                        if(angle>0)
                        {
                            direction = 1;
                        }
                        else
                        {
                            direction = 2;
                        }
                    }

                    if((direction==1 && angle < 0) || (direction ==2 && angle > 0))
                    {
                        // The polynom is not convex.
                        return 3;
                    }
                }
            }
        }

        unsigned long finalSize = myCoords.size();
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

        int angleOne = AB.Angle(BC);
        int angleTwo = BC.Angle(CD);

        //cerr << angleOne << endl;
        //cerr << angleTwo << endl;

        if(direction == -1 && angleOne != 0 && angleOne != 180)
        {
            //Detect the direction of all vectors in the polygon
            if(angleOne>0)
            {
                direction = 1;
            }
            else
            {
                direction = 2;
            }
        }

        if((direction==1 &&(angleOne < 0 || angleTwo < 0)) || (direction==2 &&(angleOne>0 || angleTwo > 0)))
        {
            // The polynom is not convex.
            return 3;
        }

        allObjects.insert(make_pair(name,new Polygon(name,myCoords)));
        if(!notInHistoric) {
            historic.push_front("PC " + name + " " + points);
            reverseHistoric.push_front("DELETE " + name);
        }

        return 0;
    }

    int Draw::AddRectangle(string name, string points, bool notInHistoric)
    {
        if(allObjects.find(name) != allObjects.end())
        {
            // This object name already exists !
            return 1;
        }

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

        if(myCoords[0] > myCoords[2] || myCoords[1] > myCoords[3])
        {
            // Your points arent corrects. I mean its not top-left and bottom-right points.
            return 3;
        }

        allObjects.insert(make_pair(name,new Rectangle(name, myCoords)));

        if(!notInHistoric) {
            historic.push_front("R " + name + " " + points);
            reverseHistoric.push_front("DELETE " + name);
        }

        return 0;
    }

    int Draw::AddIntersection(string name, string others, bool notInHistoric)
    {
        if(allObjects.find(name) != allObjects.end())
        {
            // This object name already exists !
            return 1;
        }

        vector<string> otherNames;
        stringstream myStream(others);
        while(!myStream.eof())
        {
            string tempI;
            myStream >> tempI;
            otherNames.push_back(tempI);
        }

        if(otherNames.size()<2)
        {
            // Not enough objects !
            return 2;
        }

        for(unsigned int i=0; i<otherNames.size(); i++)
        {
            if(allObjects.find(otherNames.at(i)) == allObjects.end())
            {
                // One of the composing objects does not exist !
                return 4;
            }

            for (unsigned int j=i+1; j<otherNames.size(); j++)
            {
                if (otherNames.at(j) == otherNames.at(i))
                {
                    // Object given twice !
                    return 3;
                }
            }
        }

        list<Object*> objectsToUse;
        for(unsigned int i=0; i<otherNames.size(); i++)
        {
            Object* tempObjPointer = allObjects.find(otherNames.at(i))->second;
            Object* tempObjCopyPointer = tempObjPointer->Clone();
            objectsToUse.push_back(tempObjCopyPointer);
        }
        Intersection* myIntersection = new Intersection(name, objectsToUse);
        allObjects.insert(make_pair(name,myIntersection));

        if(!notInHistoric) {
            historic.push_front("OI " + name + " " + others);
            reverseHistoric.push_front("DELETE " + name);
        }

        return 0;
    }

    int Draw::AddReunion(string name, string others, bool notInHistoric)
    {
        if(allObjects.find(name) != allObjects.end())
        {
            // This object name already exists !
            return 1;
        }

        vector<string> otherNames;
        stringstream myStream(others);
        while(!myStream.eof())
        {
            string tempI;
            myStream >> tempI;
            otherNames.push_back(tempI);
        }

        if(otherNames.size()<2)
        {
            // Not enough objects !
            return 2;
        }

        for(unsigned int i=0; i<otherNames.size(); i++)
        {
            if(allObjects.find(otherNames.at(i)) == allObjects.end())
            {
                // One of the composing objects does not exist !
                return 4;
            }

            for (unsigned int j=i+1; j<otherNames.size(); j++)
            {
                if (otherNames.at(j) == otherNames.at(i))
                {
                    // Object given twice !
                    return 3;
                }
            }
        }

        list<Object*> objectsToUse;
        for(unsigned int i=0; i<otherNames.size(); i++)
        {
            Object* tempObjPointer = allObjects.find(otherNames.at(i))->second;
            Object* tempObjCopyPointer = tempObjPointer->Clone();
            objectsToUse.push_back(tempObjCopyPointer);
        }
        Union* myUnion = new Union(name, objectsToUse);
        allObjects.insert(make_pair(name,myUnion));

        if(!notInHistoric) {
            historic.push_front("OI " + name + " " + others);
            reverseHistoric.push_front("DELETE " + name);
        }

        return 0;
    }

    void Draw::List()
    {
        map<string,Object*>::iterator i;
        for(i = allObjects.begin();i!=allObjects.end();i++)
        {
            cout << i->second->toString() << endl;
        }
    }

    int Draw::Move(string name, int dX, int dY, bool notInHistoric)
    {
        map<string,Object*>::iterator myObj = allObjects.find(name);

        if(myObj == allObjects.end())
        {
            // This object doesnt exists !
            return 1;
        }
        else
        {
            if(!notInHistoric) {
                string dxString = static_cast<ostringstream *>( &(ostringstream() << dX))->str();
                string dyString = static_cast<ostringstream *>( &(ostringstream() << dY))->str();
                string mdxString = static_cast<ostringstream *>( &(ostringstream() << (-dX)))->str();
                string mdyString = static_cast<ostringstream *>( &(ostringstream() << (-dY)))->str();
                historic.push_front("MOVE " + name + " " + dxString + " " + dyString);
                reverseHistoric.push_front("MOVE " + name + " " + mdxString + " " + mdyString);
            }
            return myObj->second->Move(dX,dY);
        }
    }

    int Draw::Save(string filename)
    {
        string adress = "saves/" + filename;
        ofstream myFile(adress.c_str());
        if(!myFile.is_open())
        {
            return 1;
        }

        myFile << "=drawingfileB3133" << endl;
        myFile << "*" << filename << endl;

        map<string,Object*>::iterator i;
        for(i=allObjects.begin();i!=allObjects.end();i++)
        {
            i->second->GetCommand(myFile);
            myFile << endl;
        }

        return 0;
    }

    int Draw::Load(string filename)
    {
        string adress = "saves/" + filename;
        ifstream saveFile(adress.c_str(), ios::in);
        if(!saveFile)
        {
            cerr << "error when opening the file : " << filename << endl;
            return 1;
        }
        else
        {
            string line;
            int succeededLines(0), totalLines(0);

            //Check if the start of the file is a file generated by our app
            getline(saveFile,line);
            if(line != "=drawingfileB3133")
            {
                cerr << "Error : this file is not a file made by our program" << endl;
                return 3;
            }
            getline(saveFile,line);
            if(line != "*"+filename)
            {
                cerr << "Error : this file is not a file made by our program" << endl;
                return 3;
            }

            // Save of the vector of object here before load
            vector<string> anteriorObjects;
            map<string,Object *>::iterator i;
            for(i=allObjects.begin();i != allObjects.end(); i++)
            {
                anteriorObjects.push_back(i->first);
            }

            stringstream commands;
            commands << saveFile.rdbuf();

            while(!commands.eof())
            {
                try {
                        succeededLines += (ExecuteCommand(commands, true) == 0);
                        totalLines++;
                }
                catch (exception e) {
                    cerr << e.what() << " when reading the saved file" << endl;
                    return 2;
                }
            }
            if(succeededLines!=totalLines)
            {
                cerr << "Warning, only " << succeededLines << " lines correctly read out of " << totalLines << " !" << endl;
                //cout << "ERR not all lines have been correctly read" << endl;
                return 3;
            }

            //TODO write reverseHistoric command...
            historic.push_front("LOAD "+filename);

            // Reverse command : delete all objects which were not in the anterior list.
            string reverseCommand = "DELETE";
            for(i = allObjects.begin();i != allObjects.end(); i++)
            {
                if(anteriorObjects.end() == find(anteriorObjects.begin(),anteriorObjects.end(),i->first))
                {
                    // This is a new object !
                    reverseCommand += " ";
                    reverseCommand += i->first;
                }
            }
            reverseHistoric.push_front(reverseCommand);
            return 0;
        }


    }

    int Draw::Delete(string names, bool notInHistoric)
    {
        vector<string> toDelete;
        stringstream ss(names);
        string current;

        while(!ss.eof())
        {
            if (ss >> current)
            {
                toDelete.push_back(current);
                map<string,Object*>::iterator myObj = allObjects.find(current);
                if(myObj == allObjects.end())
                {
                    // This object doesnt exists !
                    return 1;
                }
            }
            else
            {
                // This is not a correct name.
                return 1;
            }
        }

        string reverseCommand("MULT"), command("DELETE"), temp;
        // temp = to_string(toDelete.size()); TODO : Put this back

        stringstream tmp;
        tmp << toDelete.size();
        tmp >> temp;

        reverseCommand += temp;

        stringstream ss2;

        for(unsigned int i=0; i<toDelete.size(); i++)
        {
            command += " " + toDelete.at(i);

            temp="";
            allObjects.find(toDelete.at(i))->second->GetCommand(ss2);
            while(ss2)
            {
                string line;
                getline(ss2,line);
                temp += line;
                temp += '\n';
            }
            //cerr << ":"<<temp<<endl;
            reverseCommand += "\n" + temp;

            delete allObjects.find(toDelete.at(i))->second;
            allObjects.erase(toDelete.at(i));
        }

        if(!notInHistoric)
        {
            historic.push_front(command);
            reverseHistoric.push_front(reverseCommand);
        }
        return 0;
    }

    int Draw::Clear()
    {
        int result = Save("tmpClearSave");
        if(result == 0)
        {
            map<string,Object*>::iterator i;
            string names;

            for(i=allObjects.begin();i != allObjects.end();i++)
            {
                names += (i->first)+" ";
            }
            names.pop_back();

            if(names != "")
            {
                Delete(names);
            }

            historic.push_front("CLEAR");
            reverseHistoric.push_front("LOAD tmpClearSave");

            return 0;
        }
        else
        {
            return 1;
        }
    }

    int Draw::Undo()
    {
        if(historic.size() == 0)
        {
            //The historic is empty
            return 1;
        }

        if(historicPosition == historic.size())
        {
            //We are at the end of the historic :(

            return 1;
        }

        list<string>::iterator i = reverseHistoric.begin();
        advance(i,historicPosition);

        cerr << "The UNDO method try to do this : "+*i << endl << "End of show" << endl;

        stringstream mySS(*i);/*TO OPTI********************************************************************************/
        ExecuteCommand(mySS,true);
        historicPosition++;

        return 0;
    }

    int Draw::Redo()
    {
        if(historic.size() == 0)
        {
            //The historic is empty
            return 1;
        }

        if(historicPosition == 0)
        {
            //We are at the beginning of the historic :(
            return 1;
        }

        historicPosition--;
        list<string>::iterator i = historic.begin();
        advance(i,historicPosition);

        //cerr << "The REDO method try to do this : "+*i << endl;

        stringstream mySS(*i);/*TO OPTI********************************************************************************/
        ExecuteCommand(mySS,true);

        return 0;
    }

    int Draw::Hit(string name, int x, int y)
    {
        map<string,Object*>::iterator myObj = allObjects.find(name);

        if(myObj == allObjects.end())
        {
            // This object doesnt exists !
            return 2;
        }

        bool returnedBool = myObj->second->Hits(Point(x,y));
        if(returnedBool == 0)
        {
            cout << "NO" <<endl;
            return 0;
        }
        else if(returnedBool == 1)
        {
            cout << "YES" <<endl;
            return 0;
        }
        return returnedBool;
    }

    int Draw::Mult(stringstream &ss, int cmdNum)
    {
        for(int currentCmdNum=0; currentCmdNum<cmdNum; currentCmdNum++)
        {
            ExecuteCommand(ss, true);
        }
        //cout << "End of MULT"<<cmdNum << endl;
        return 0;
    }

int Draw::ExecuteCommand(stringstream &ss, bool notInHistoric) {

    string cmdType;
    ss >> cmdType;
    ss.ignore();

    //If a command is done after few UNDO we need to delete these from the historic
    if(!notInHistoric && historicPosition != 0 && cmdType!="LIST" && cmdType != "HIT" && cmdType != "SAVE" && cmdType!="UNDO" && cmdType!="REDO")
    {
        list<string>::iterator i = historic.begin();
        advance(i,historicPosition);
        historic.erase(historic.begin(),i);

        i=reverseHistoric.begin();
        advance(i,historicPosition);
        reverseHistoric.erase(reverseHistoric.begin(),i);

        cerr << "Historic cleaned" << endl;

        historicPosition = 0;
    }

    int returnCode(0);

    if(cmdType=="S")
    {
        string name;
        string points;

        ss >> name;
        getline(ss,points);

        returnCode = AddSegment(name,points, notInHistoric);
    }
    else if(cmdType=="R")
    {
        string name;
        string points;

        ss >> name;
        getline(ss,points);
        returnCode = AddRectangle(name,points, notInHistoric);
    }
    else if(cmdType=="PC")
    {
        string name;
        string points;

        ss >> name;
        getline(ss,points);

        returnCode = AddPolygon(name,points, notInHistoric);
    }
    else if(cmdType=="OR")
    {
        string name;
        string others;

        ss >> name;
        getline(ss, others);

        returnCode = AddReunion(name, others, notInHistoric);
    }
    else if(cmdType=="OI")
    {
        string name;
        string others;

        ss >> name;
        getline(ss, others);

        returnCode = AddIntersection(name, others, notInHistoric);
    }
    else if(cmdType=="HIT")
    {
        string Name;
        int x, y;

        if(!(ss >> Name))
        {
            returnCode = 2;
        }
        else if(!(ss >> x >> y))
        {
            returnCode = 3;
        }
        else
        {
            returnCode = Hit(Name,x,y);
        }
    }
    else if(cmdType=="DELETE")
    {
        string names;
        getline(ss,names);

        returnCode = Delete(names,notInHistoric);

    }
    else if(cmdType=="MOVE")
    {
        {
            string Name;
            int dX, dY;

            if(!(ss >> Name))
            {
                returnCode = 1;
            }
            else if(!(ss >> dX >> dY))
            {
                    returnCode = 2;
            }
            else
            {
                returnCode = Move(Name,dX,dY,notInHistoric);
            }
        }
    }
    else if(cmdType=="LIST")
    {
        List();
    }
    else if(cmdType=="UNDO")
    {
        returnCode=Undo();
    }
    else if(cmdType == "REDO")
    {
        returnCode=Redo();
    }
    else if(cmdType=="LOAD")
    {
        string filename;
        ss >> filename;
        returnCode=Load(filename);
    }
    else if(cmdType=="SAVE")
    {
        string filename;
        ss >> filename;
        returnCode=Save(filename);
    }
    else if(cmdType=="CLEAR")
    {
        returnCode = Clear();
    }
    else if(cmdType.substr(0,4)=="MULT")
    {
        string cmdNumStr=cmdType.substr(4,cmdType.size()-4);
        stringstream cmdNumSS(cmdNumStr);
        int cmdNum;
        cmdNumSS >> cmdNum;
        returnCode = Mult(ss, cmdNum);
    }
    else if(cmdType=="EXIT")
    {
        map<string,Object *>::iterator i;
        for(i = allObjects.begin();i!=allObjects.end();i++)
        {
            delete i->second;
        }
        exit(0);
    }

    if(!notInHistoric)
    {
        printResult(cmdType, returnCode);
    }

    //TODO:Delete the oldest command in historic if there is more than 20 commands.

    return 0;
}

void Draw::printResult(string cmdType, int returnCode)
{
    if((cmdType=="LIST" || cmdType=="HIT") && returnCode==0)
    {
        //nothing
    }
    else if(returnCode==0)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
        if (cmdType == "S") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#Incorrect name" << endl;
                    break;
                case 2 :
                    cout << "#Invalid format or number of coordinates" << endl;
                    break;
                default:break;
            }
        }
        else if (cmdType == "R") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#Incorrect name" << endl;
                    break;
                case 2 :
                    cout << "#Incorrect number of coordinates" << endl;
                    break;
                case 3 :
                    cout << "#Incorrect point placement" << endl;
                    break;
                default:break;
            }
        }
        else if (cmdType == "PC") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#Incorrect name" << endl;
                    break;
                case 2 :
                    cout << "#Incorrect number of coordinates" << endl;
                    break;
                case 3 :
                    cout << "#Non convex polygon" << endl;
                    break;
                case 4 :
                    cout << "#Same coordinates used several times" << endl;
                    break;
                default:break;
            }
        }
        else if (cmdType == "OR") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#Incorrect name" << endl;
                    break;
                case 2 :
                    cout << "#Incorrect number of objects" << endl;
                    break;
                case 3 :
                    cout << "#Several uses of the same object" << endl;
                    break;
                case 4 :
                    cout << "#Inclusion of a non-existant object" << endl;
                    break;
                default:break;
            }
        }
        else if (cmdType == "OI") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#Incorrect name" << endl;
                    break;
                case 2 :
                    cout << "#Incorrect number of objects" << endl;
                    break;
                case 3 :
                    cout << "#Several uses of the same object" << endl;
                    break;
                case 4 :
                    cout << "#Intersection with a non-existant object" << endl;
                    break;
                default:break;
            }
        }
        else if (cmdType == "HIT") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#The point doesn't hit the object" << endl; //TODO: Not used because it have been replaced by YES/NO
                    break;
                case 2 :
                    cout << "#Incorrect name" << endl;;
                    break;
                case 3 :
                    cout << "#Incorrect format or number of coordinates" << endl;;
                    break;
                default:break;
            }
        }
        else if (cmdType == "DELETE") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#Incorrect name" << endl;
                    break;
                default:break;
            }
        }
        else if (cmdType == "MOVE") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#Incorrect name" << endl;
                    break;
                case 2 :
                    cout << "#Incorrect format or number of coordinates" << endl;
                    break;
                default:break;
            }
        }
        else if (cmdType == "UNDO") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#No action to undo" << endl;
                    break;
                default:break;
            }
        }
        else if (cmdType == "REDO") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#No action to redo" << endl;
                    break;
                default:break;
            }
        }
        else if (cmdType == "LOAD") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#The file is not accessible for reading" << endl;
                    break;
                case 2 :
                    cout << "#The file reading generated an exception" << endl;
                    break;
                case 3 :
                    cout << "#The program does not understand the file" << endl;
                    break;
                default:break;
            }
        }
        else if (cmdType == "SAVE") {
            switch (returnCode)
            {
                case 1 :
                    cout << "#The file is not accessible for writing" << endl;
                    break;
                case 2 :
                    cout << "#Invalid filename" << endl;
                    break;
                default:break;
            }
        }
    }
}

//Constructors
Draw::Draw() : historicPosition(0)
{}
