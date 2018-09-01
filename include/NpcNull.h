/**
*@file NpcNull.h
*@brief Representation of a null NPC in game.
*@author
*/

#ifndef NPCNULL_H
#define NPCNULL_H

#include "NpcBase.h"
#include <fstream>


class NpcNull : public NpcBase
{
    public:
        NpcNull();

        /**
        *@brief outputs text saying no npc exists in this room.
        */
        void speak();

    protected:

    private:
};

#endif // NPCNULL_H
