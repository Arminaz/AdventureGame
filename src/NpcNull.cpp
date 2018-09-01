#include "NpcNull.h"
#include <iostream>

using namespace std;

NpcNull::NpcNull()
{
}


void NpcNull::speak()
{
    cout << "There is no one to speak to in this room." << endl;
}
