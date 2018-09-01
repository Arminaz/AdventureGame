/**
*@file Room.h
*@brief Defines the properties of a room in the game.
*@author
*/


#ifndef ROOM_H
#define ROOM_H

#include "GameObjectCreator.h"
#include "Alien.h"
#include "Combat.h"
#include "Player.h"
#include "Puzzle.h"
#include "Interface.h"
#include "Item.h"
#include "NpcBase.h"



#include <string.h>
#include <fstream>

using namespace std;


/**
*A class handling the implementation of the game's rooms.
*/
class Room
{
    public:
        /**
        *@brief room's constructor; initializes all pointers to null.
        */
        Room();

        /**
        *@brief copy constructor.
        *@param roomToCopy the room to be copied.
        */
        Room(const Room& roomToCopy);

        /**
        *@brief room's destructor.
        */
        virtual ~Room();

        /**
        *@brief Initializes the room with the correct data.
        *@param roomData the file containing this room's data (such as roomID, and which rooms are adjacent to it).
        *@param roomDescriptions file containing each room's description.
        *@throw invalid_input if data cannot be read from roomData or roomDescription, or data throws input stream into fail state.
        */
        void getRoomInfo(ifstream& roomData, ifstream& roomDescriptions);

        /**
        *@brief Handles logic associated with first entering a room (such as combat).
        *@param player represents the created player object in the world.
        */
        void enterRoom(Player* player);

        /**
        *Plays the puzzle at this room, if one exists.
        *@throw invalid_input if there is no puzzle in this room (ie. puzzle == nullptr).
        */
        void playPuzzle();

        /**
        *Function displaying the room's description.
        *Also adds any potential items in the room to the player's inventory.
        *@param player the representation of the player in-game.
        */
        void examineRoom(Player* player);

        /**
        *@brief talks to an npc in this room, if one exists.
        */
        void talkToNpc();

        /**
        *@return this room's roomID.
        */
        int getRoomID() const;

        /**
        *@return northRoom, the ID of the room to the north.
        */
        int getNorthRoom() const;
        /**
        *@return eastRoom, the ID of the room to the east.
        */
        int getEastRoom() const;
        /**
        *@return southRoom, the ID of the room to the south.
        */
        int getSouthRoom() const;
        /**
        *@return westRoom, the ID of the room to the west.
        */
        int getWestRoom() const;

        /**
        *@return puzzleID, the identification of this room's puzzle.
        */
        int getPuzzleID() const;

        /**
        *@return itemID, the identification of this room's item.
        */
        int getItemID() const;

        /**
        *@return npcID, the ID of the npc in this room.
        */
        int getNpcID() const;

        /**
        *@return roomLockedByPuzzle, an indicator if one of the adjacent rooms is locked and innaccessable because of a puzzle.
        */
        PlayerChoices getLockedRoom() const;

        /**
        *@return canEnemySpawnHere, a bool indicating whether or not an enemy can spawn in this particular room.
        */
        bool getCanEnemySpawnHere() const;

        /**
        *@return true if this room's puzzle pointer != null, else return false.
        */
        bool doesRoomHavePuzzle() const;

        /**
        *@return true if this room has an npc (ie. npcChar != nullptr).
        */
        bool doesRoomHaveNpc() const;

        /**
        *@return roomName, the name of this room.
        */
        string getRoomName() const;




    protected:

    private:
        GameObjectCreator* factory;

        Alien* enemy;
        Puzzle* puzzle;
        Item* itemInRoom;
        PlayerChoices roomLockedByPuzzle;
        NpcBase* npcChar;

        int roomID;
        int northRoom, eastRoom, southRoom, westRoom;
        int puzzleID;
        int itemID;
        int npcID;


        std::string roomName;
        std::string roomDescription;

        bool canEnemySpawnHere;
};

#endif // ROOM_H
