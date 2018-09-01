#include "GameOverInterface.h"
#include "Exceptions.h"

GameOverInterface::GameOverInterface()
{
    cout << "Game Over." << endl;

    actionMap.insert(pair<char, PlayerChoices>('q', quitGame));

    cout << "Do you want to load a previous save or quit the game?";
}

void GameOverInterface::getHelp()
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t Help: Game Over" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "L: Load a previous save." << endl;
    cout << "Q: Quit the game." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << '\n';
}
