#include "NullPuzzle.h"

#include <iostream>

using namespace std;

NullPuzzle::NullPuzzle()
{
    //ctor
}

bool NullPuzzle::doPuzzle()
{
    cout << "No puzzle exists in this room." << endl;
    return true;
}
