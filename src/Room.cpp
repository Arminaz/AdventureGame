#include "Room.h"
#include "Interface.h"
#include "RoomInterface.h"
#include "L_StringHelper.h"
#include "GameHelper.h"
#include "Exceptions.h"
#include "ShipPart.h"
#include "NullPuzzle.h"
#include "NpcNull.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctype.h>
#include <typeinfo>

using namespace std;

Room::Room()
{
    factory = new GameObjectCreator();

    itemInRoom = nullptr;
    enemy = nullptr;
    puzzle = nullptr;
    npcChar = nullptr;
}

Room::~Room()
{
    delete factory;
    delete puzzle;
    delete npcChar;
    delete itemInRoom;
}

Room::Room(const Room& roomToCopy)
{
    factory = new GameObjectCreator();

    this->itemInRoom = factory->createItem(-5);
    this->enemy = nullptr;
    this->puzzle = factory->createPuzzle(-5);
    this->npcChar = factory->createNpc(-5);

    this->roomID = roomToCopy.itemID;
    this->northRoom = roomToCopy.northRoom;
    this->eastRoom = roomToCopy.eastRoom;
    this->southRoom = roomToCopy.southRoom;
    this->westRoom = roomToCopy.westRoom;
    this->roomName = roomToCopy.roomName;
    this->canEnemySpawnHere = roomToCopy.canEnemySpawnHere;
    this->puzzleID = roomToCopy.puzzleID;
    this->roomLockedByPuzzle = roomToCopy.roomLockedByPuzzle;
    this->itemID = roomToCopy.itemID;
    this->npcID = roomToCopy.npcID;
}


void Room::getRoomInfo(ifstream& roomData, ifstream& roomDescriptions)
{
    //Initialize all data for this room with data from the input files.
    getline(roomDescriptions, roomDescription, '\n');
    L_StringHelper::printTextWrap(roomDescription);

    roomData >> roomID;
    roomData >> northRoom >> eastRoom >> southRoom >> westRoom;

    roomData.ignore();
    getline(roomData, roomName, '\n');

    roomData >> canEnemySpawnHere;

    roomData >> puzzleID;
    puzzle = factory->createPuzzle(puzzleID);

    int lockedRoom;
    roomData >> lockedRoom;
    roomLockedByPuzzle = static_cast<PlayerChoices>(lockedRoom);

    roomData >> itemID;
    itemInRoom = factory->createItem(itemID);

    roomData >> npcID;
    npcChar = factory->createNpc(npcID);

    if(!roomData || !roomDescriptions)
    {
        throw invalid_input("The file roomData contains invalid/corrupt/missing data.");
    }
}

void Room::enterRoom(Player* player)
{
    //Determine if this room is going to spawn an item, as long as this room does not currently have an item.
    if((rand() % 100 + 1) > 60 && itemID == 0)
    {
        delete itemInRoom;

        itemID = rand() % 2 + 1;
        itemInRoom = factory->createItem(itemID);
    }


    if(!player->isCharDead())
    {
        cout << "\nNow entering " << roomName << endl;

        //decrease player's oxygen by 5 as they enter the room.
        player->setOxygen(player->getOxygen() - 5);
        cout << "Your new oxygen level is: " << player->getOxygen() << "%" << endl;

        //if this room can spawn an enemy, and one does spawn given random chance, have the player fight it!
        if(canEnemySpawnHere && (rand() % 100 + 1) > 50)
        {
            enemy = factory->createAlien();

            cout << "An alien jumps out at you!" << endl;
            Combat* battle = new Combat(player, enemy);

            if(battle->fight())
            {
                cout << "You win!" << endl;
                delete battle;
                delete enemy;
                enemy = nullptr;
            }
            else
            {
                //this is death by combat
                delete battle;

                string deathMessage = "You have died in combat.";
                GameHelper::gameOver(deathMessage);
            }
        }
        //check the player's status to see if they ran out of oxygen
        player->checkCurrentStatus();
    }
    else
    {
        //this is death by running out of oxygen
        string deathMessage = "You have run out of oxygen, and the toxic fumes of the planet cause you to asphyxiate.";
        GameHelper::gameOver(deathMessage);
    }
}

void Room::playPuzzle()
{
    if(puzzle->doPuzzle())
    {
        if(roomLockedByPuzzle != null)
        {
            roomLockedByPuzzle = null;
            cout << "You hear the snapping of a lock beside you. The locked door groans open." << endl;
        }
    }
    else
    {
        //The user has lost the puzzle, so the game is over.
        ifstream text("./files/puzzleDeath.dat");

        string deathMessage;
        getline(text, deathMessage, '\n');

        GameHelper::gameOver(deathMessage);
    }
}


void Room::examineRoom(Player* player)
{
    cout << '\n' << roomDescription << endl << endl;

    //If there is an item in the room, have them pick it up.
    if(itemInRoom->getItemType() != nullItem)
    {
        cout << "After exploring, you find a " << itemInRoom->printItemName() << "!" << endl;

        //if this is a ship part, cast it from an item* to a shipPart* and check if it is phony.
        if(itemInRoom->getItemType() == shipPart)
        {
            ShipPart* shipPart = static_cast<ShipPart*>(itemInRoom);

            //If the item is phony, ask the user if they wish to pick it up. Only 'y' will add the item to the player's inventory.
            if(shipPart->isPartPhony())
            {
                cout << "This ship part looks...wrong. Do you still wish to pick it up? [Y/N]";
                char ans;
                cin >> ans;
                cin.ignore(500, '\n');
                ans = tolower(ans);
                if(ans != 'y')
                {
                    return;
                }
            }
        }

        //Add the item to the player's inventory.
        cout << itemInRoom->printItemName() << " added to inventory." << endl << endl;
        player->inventory->addItem(itemInRoom);
        itemInRoom = factory->createItem(-5);
        itemID = 0;
    }
    else
    {
        cout << "After exploring, you find nothing of value." << endl << endl;
    }
}

void Room::talkToNpc()
{
    npcChar->speak();
}

int Room::getRoomID() const
{
    return roomID;
}

int Room::getNorthRoom() const
{
    return northRoom;
}

int Room::getEastRoom() const
{
    return eastRoom;
}

int Room::getSouthRoom() const
{
    return southRoom;
}

int Room::getWestRoom() const
{
    return westRoom;
}
int Room::getPuzzleID() const
{
    return puzzleID;
}

int Room::getItemID() const
{
    return itemID;
}

int Room::getNpcID() const
{
    return npcID;
}

PlayerChoices Room::getLockedRoom() const
{
    return roomLockedByPuzzle;
}

bool Room::doesRoomHavePuzzle() const
{
    return (typeid(*puzzle) != typeid(NullPuzzle));
}

bool Room::doesRoomHaveNpc() const
{
    return (typeid(*npcChar) != typeid(NpcNull));
}

string Room::getRoomName() const
{
    return roomName;
}

bool Room::getCanEnemySpawnHere() const
{
    return canEnemySpawnHere;
}

