/**
*@file Npc.h
*@brief Representation of an NPC ingame.
*@author
*/

#ifndef NPC_H
#define NPC_H

#include "NpcBase.h"

#include <Character.h>
#include <iostream>
#include <fstream>

using namespace std;

class Npc : public NpcBase
{
    public:
        /**
        *@brief constructs a new NPC.
        *@param npcData the file containing all this npc's data.
        */
        Npc(ifstream& npcData);

        /**
        *@brief displays any dialogue that the npc has.
        */
        virtual void speak();

        /**
        *@brief destructor.
        */
        ~Npc();

    private:
        int numOfStrings;
        bool haveSpoken;
};

#endif // NPC_H
