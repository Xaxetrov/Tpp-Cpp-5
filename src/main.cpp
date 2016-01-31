#include <iostream>
#include "Rectangle.h"
#include "Draw.h"

using namespace std;

int main() {

    Draw d;
    string s;
    while(1)
    {
        getline(cin, s);
        stringstream ss(s);
        d.ExecuteCommand(ss);
    }
}