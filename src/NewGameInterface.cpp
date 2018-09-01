#include "NewGameInterface.h"
#include "Exceptions.h"

#include <iostream>
#include <ctype.h>

using namespace std;

NewGameInterface::NewGameInterface()
{
    //assign actions to various character inputs
    actionMap.insert(pair<char, PlayerChoices>('n', newGame));
    actionMap.insert(pair<char, PlayerChoices>('l', loadGame));
    actionMap.insert(pair<char, PlayerChoices>('q', quitGame));

    cout << "You can start a new game by typing 'n', or load a game by typing 'l'." << endl;
}

void NewGameInterface::getHelp()
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t Help: Start Menu" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Here are your options while in the start menu: " << endl;
    cout << "N: Start a new game." << endl;
    cout << "L: Load a previous save game." << endl;
    cout << "Q: Quit game." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\n";

}
