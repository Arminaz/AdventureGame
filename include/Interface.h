/**
*@file Interface.h
*@brief Base class for all interfaces in the game.
*@author
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

enum PlayerChoices {null, help, quitGame, newGame, loadGame, saveGame,
                    attack, defend,
                    moveNorth, moveEast, moveSouth, moveWest, talk, playPuzzle,
                    examine, useItem};


/**
*Base class handling input from the user.
*/

class Interface
{
    public:
        Interface();
        virtual ~Interface() {}

        /**
        *@brief Returns input from the player.
        *@throw invalid_input if input is invalid.
        */
        PlayerChoices getInput();

        /**
        *@brief displays a list of options available to the player.
        */
        virtual void getHelp() = 0;

        /**
        *@brief Clears all input from the cin input stream.
        *@param iStr the input stream that needs to be cleared of input data.
        */
        static void clearInputStream(istream& iStr);

    protected:
        char userInput;

        /**
        *Defines all possible actions the user could enter.
        */
        map<char, PlayerChoices> actionMap;
    private:
};

#endif // INTERFACE_H
