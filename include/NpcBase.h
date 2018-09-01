/**
*@file NpcBase.h
*@brief Base class for all NPCs in the game.
*@author
*/

#ifndef NPCBASE_H
#define NPCBASE_H

#include <string>

using namespace std;

class NpcBase
{
    public:
        NpcBase();
        virtual ~NpcBase();

        /**
        *@brief virtual function for speaking with an npc.
        */
        virtual void speak() = 0;

    protected:
        string* dialog;

    private:
};

#endif // NPCBASE_H
