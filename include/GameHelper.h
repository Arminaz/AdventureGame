/**
*@file GameHelper.h
*@brief Collection of static functions to help with some basic game features.
*@author
*/

#ifndef GAMEHELPER_H
#define GAMEHELPER_H

#include "RoomManager.h"
#include "Player.h"
/**
*A class containing core features (such as what happens when the user quits or dies, and saving a game) kept separate in this helper class.
*/

class GameHelper
{
    public:
        /**
        *@brief function that prints to the screen the opening text.
        */
        static void newGame();

        /**
        *@brief function that loads data from a file into the player object and the roomManager object.
        *@param player the player representation in the game.
        *@param roomManager the representation of the rooms in the game.
        *@throw invalid_parameter if player or roomManager is not equal to nullptr.
        */
        static void loadGame(Player*& player, RoomManager*& roomManager);

        /**
        *@brief handles the end-game (determining whether the user won or lost).
        *@param player the player object in-game.
        */
        static void endGame(const Player* player);

        /**
        *@brief Handles game over functionality (ie. what happens when the player dies).
        *@param deathMessage the message printed to the screen when the player dies.
        */
        static void gameOver(string& deathMessage);

        /**
        *@brief saves the current state of the game to a data file.
        *@param roomManager the representation of the states of all the rooms at this time.
        *@param player the representation of the player object in-game.
        */
        static void saveGame(const RoomManager* roomManager, const Player* player);

    protected:

    private:
};

#endif // GAMEHELPER_H
