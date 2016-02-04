/***********************************************************************************************************************
    Point  -  description
    ---------------------
    begin : 10/01/2015
    copyright : (C) 2016 by Edern Haumont & Théo Thibault
***********************************************************************************************************************/

#ifndef TP_CPP_5_POINT_H
#define TP_CPP_5_POINT_H

//----------------------------------------------------------------------------------------------------------------------
// The Segment class represents a segment defined by its two coordinates
//----------------------------------------------------------------------------------------------------------------------
class Point {

//--------------------------------------------------------------------------------------------------------------- Public
public :

    //Inline getters and setters
    int GetX() {return x;}
    int GetY() {return y;}
    void SetX(int myX) {x = myX;}
    void SetY(int myY) {y = myY;}

    //Constructor
    Point(int myX, int myY);
    virtual ~Point();
    //Other methods
    void Move(int dX, int dY);
    // Manual :
    // Moves the segment position by dX and dY

//private attributes
private :
    int x, y;
};


#endif //TP_CPP_5_POINT_H
