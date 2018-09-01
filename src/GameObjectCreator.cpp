#include "GameObjectCreator.h"
#include "L_StringHelper.h"

#include "./Spelling.h"
#include "./MathPuzzle.h"
#include "./LockpickPuzzle.h"
#include "./WordCode.h"
#include "./HackingPuzzle.h"
#include "./NullPuzzle.h"

#include "Npc.h"
#include "NpcNull.h"

#include "HealthPack.h"
#include "OxygenPack.h"
#include "ShipPart.h"
#include "NullItem.h"

GameObjectCreator::GameObjectCreator()
{
    //ctor
}


Item* GameObjectCreator::createItem(const int& itemID)
{
    //spawn an item depending on what the value of itemID is
    switch(itemID)
    {
        case 1 : return new HealthPack();
        case 2 : return new OxygenPack();
        case 10 : return new ShipPart(false);
        case 11 : return new ShipPart(true);
        default : return new NullItem();
    }
}


NpcBase* GameObjectCreator::createNpc(const int& npcID)
{
    std::ifstream data;
    switch(npcID)
    {
        case 1 : data.open("./files/donaldPeirce.dat"); return new Npc(data);
        case 2 : data.open("./files/changMcCracken.dat"); return new Npc(data);
        case 3 : data.open("./files/alexMason.dat"); return new Npc(data);
        case 4 : data.open("./files/henryAsh.dat"); return new Npc(data);
        case 5 : data.open("./files/mariannaKeaton.dat"); return new Npc(data);
        default : return new NpcNull();
    }
    //return new Npc(data);
}


Puzzle* GameObjectCreator::createPuzzle(const int& puzzleID)
{
    switch(puzzleID)
    {
        case 1 : //create a new spelling puzzle
            {
                return new Spelling("Aesthetic");
            }
        case 2 : //create a new math puzzle, with a randomly generated number
            {
                int randAnswer = rand() % 999 + 1;
                return new MathPuzzle(L_StringHelper::toString(randAnswer));
            }
        case 3 : //create a new lockpick puzzle
            {
                return new LockpickPuzzle();
            }
        case 4 : //create a new word code puzzle with the password set here
            {
                return new WordCode("Opulence");
            }
        case 5 : //create a new hacking puzzle
            {
                return new HackingPuzzle();
            }
        default : //set the puzzle pointer to the NullPuzzle class
            {
                return new NullPuzzle();
            }
    }
}

Alien* GameObjectCreator::createAlien()
{
    int health = (rand() % 8 + 5) * 4;
    int damage = (rand() % 3 + 3) * 2;

    return new Alien(health, damage);
}
