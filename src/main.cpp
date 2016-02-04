#include <iostream>
#include "Rectangle.h"
#include "Draw.h"

using namespace std;

int main() {

    Draw d;
    string s;
    int needExit = 0;

    while(!needExit)
    {
        getline(cin, s);
        stringstream ss(s);
        needExit=d.ExecuteCommand(ss);
    }
}