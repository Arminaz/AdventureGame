#include "CombatInterface.h"
#include "Exceptions.h"

#include <ctype.h>
using namespace std;

CombatInterface::CombatInterface()
{
    cout << "Now entering combat!" << endl;

    //assign actions to the actionMap
    actionMap.insert(pair<char, PlayerChoices>('a', attack));
    actionMap.insert(pair<char, PlayerChoices>('d', defend));
    actionMap.insert(pair<char, PlayerChoices>('i', useItem));
}


void CombatInterface::getHelp()
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t Help: Combat" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Your options for combat are:" << endl;
    cout << "A: Attack your foe." << endl;
    cout << "D: Defend against the next attack." << endl;
    cout << "I: Use item." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\n";

}
