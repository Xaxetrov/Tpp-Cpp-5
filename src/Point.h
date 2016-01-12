//
// Created by Edern Haumont on 12/01/2016.
//

#ifndef TP_CPP_5_POINT_H
#define TP_CPP_5_POINT_H


class Point {

public :

    //Inline getters and setters
    int GetX() {return x;}
    int GetY() {return y;}
    void SetX(int myX) {x = myX;}
    void SetY(int myY) {y = myY;}

    //Constructor
    Point(int myX, int myY);

//private attributes
private :
    int x, y;
};


#endif //TP_CPP_5_POINT_H
