#include <iostream>
#include "Rectangle.h"
#include "Draw.h"

using namespace std;

int main() {
    /*Object* o1 = new Rectangle("BLA");
    o1->Move(1,2);
*/
    Draw d;
    string s;
    while(1)
    {
        getline(cin, s);
        d.ExecuteCommand(s);
    }
}