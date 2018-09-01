/**
*@file RoomManager.h
*@brief Manages the array of the game's rooms.
*@author
*/

#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include "Room.h"
#include "Interface.h"
#include "Player.h"

#include <fstream>

/**
*A class handling the management of the game's rooms, such as moving between rooms and handling input returned by the interface classes.
*/

class RoomManager
{
    public:
        /**
        *@brief Creates the gameMap and initializes each array element with its correct data.
        */
        RoomManager();

        /**
        *@brief constructor taking in an input file, namely one that contains a previously saved game state.
        *@param inputFile the file from which data will be read.
        *@throw invalid_input if data cannot be read from file.
        */
        RoomManager(ifstream& inputFile);

        /**
        *@brief deletes gameMap.
        */
        virtual ~RoomManager();

        /**
        *@brief Lets the user move through each of the rooms depending on their movement input.
        *@param player the representation of the player object in-game.
        */
        void moveThroughRooms(Player* player);

        /**
        *@return numOfRooms, representing the number of rooms this game has.
        */
        int getNumRooms() const;

        /**
        *@return currentRoom, the player's current room in the game.
        */
        int getCurrentRoom() const;

        /**
        *@return movesLeft, the number of moves the player has left to make.
        */
        int getMovesLeft() const;

        /**
        *@param index specifies the index of the gameMap to access.
        *@return the room in the gameMap array at the location specified by index.
        *@throw invalid_index if index < 0 or if index >= the size of the gameMap
        */
        Room& getRoom(int index) const;

    protected:

    private:
        int getNextRoom(PlayerChoices& playerInput) const;

        int numOfRooms;
        int currentRoom;
        Room* gameMap;

        /**
        *A variable containing how many moves the player has left to make. If this reaches 0, the game will end.
        */
        int movesLeft;
};

#endif // ROOMMANAGER_H
