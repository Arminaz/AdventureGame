/**
*@file RoomInterface.h
*@brief Handles input relating to the player's options while in a room.
*@author
*/

#ifndef ROOMINTERFACE_H
#define ROOMINTERFACE_H

#include "Interface.h"
#include "Room.h"


class RoomInterface : public Interface
{
    public:
        /**
        *@brief Initializes actionMap with appropriate data.
        *@param thisRoom the current room that the player is in.
        */
        RoomInterface(Room* thisRoom);

        /**
        *@brief Displays a list of options available to the user.
        */
        virtual void getHelp();
    protected:
    private:
        Room* currentRoom;
};

#endif // ROOMINTERFACE_H
