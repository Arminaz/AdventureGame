#ifndef GAMEOBJECTCREATOR_H
#define GAMEOBJECTCREATOR_H

#include "Item.h"
#include "NpcBase.h"
#include "Puzzle.h"
#include "Alien.h"

class GameObjectCreator
{
    public:
        GameObjectCreator();

        /**
        *@brief creates an item based on the itemID
        *@param itemToSpawn the ID of the item that is going to be created.
        */
        Item* createItem(const int& itemID);

        /**
        *@brief creates an npc depending on the npcID.
        *@param npcID the id of the npc to be created.
        */
        NpcBase* createNpc(const int& npcID);

        /**
        *@brief creates a new puzzle based on the puzzleID
        *@param puzzleID the ID of the puzzle set to be initialized in this room. A value > 5 or <= 0 means no puzzle.
        */
        Puzzle* createPuzzle(const int& puzzleID);

        Alien* createAlien();

    protected:

    private:
};

#endif // GAMEOBJECTCREATOR_H
