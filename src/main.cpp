#include <iostream>
#include "Rectangle.h"
#include "Draw.h"

using namespace std;

int main() {

    Draw d;
    string s;
    //while(1)
    {
        //getline(cin, s);
        s = "MULT4\nCMD 1\nCMD 2\nCMD 3\nCMD 4\nCMD 5\nCMD 6\n";
        d.ExecuteCommand(s);
    }
}