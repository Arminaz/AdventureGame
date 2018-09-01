#include "GameHelper.h"
#include "Interface.h"
#include "GameOverInterface.h"
#include "Room.h"
#include "RoomManager.h"
#include "Player.h"
#include "Item.h"
#include "HealthPack.h"
#include "OxygenPack.h"
#include "ShipPart.h"
#include "Exceptions.h"

#include <fstream>
#include <string>

#include "L_StringHelper.h"

using namespace std;

void GameHelper::newGame()
{
    //get the data from the file.
    ifstream newGameText("./files/newGameText.dat");
    string firstParagraph;
    string secondParagraph;

    getline(newGameText, firstParagraph, '\n');
    getline(newGameText, secondParagraph, '\n');

    //display the opening paragraphs of the game.

    L_StringHelper::printTextWrap(firstParagraph);
    L_StringHelper::printTextWrap(secondParagraph);
    cout << "\n" << firstParagraph << endl << endl;
    cout << secondParagraph << endl << endl;

    cout << "Press enter to continue." << endl;
    //cin.ignore();
    cin.ignore( 500, '\n' );
}

void GameHelper::loadGame(Player*& player, RoomManager*& roomManager)
{
    if(player != nullptr || roomManager != nullptr)
    {
        throw invalid_parameter("Invalid argument passed to loadGame.");
    }
    //open the data from the save file
    ifstream saveData;
    saveData.open("./saveData.out");

    if(saveData.good())
    {
        //initialize the RoomManager with the data contained in the saveData file
        roomManager = new RoomManager(saveData);

        //create a new player object with their saved stats
        int health, oxygen;
        saveData >> health >> oxygen;
        player = new Player(health, 10, oxygen);

        //Read in the number of ship parts the player has collected from the file.
        int numOfShipParts;
        saveData >> numOfShipParts;

        //read in whether the player has collected a phony ship part or not
        bool hasPhonyPart;
        saveData >> hasPhonyPart;
        player->inventory->setHasPhonyShipPart(hasPhonyPart);

        for(int i = 0; i < numOfShipParts; i++)
        {
            Item* shipPart = new ShipPart(false);
            player->inventory->addItem(shipPart);
        }
        int itemFromFile;
        saveData >> itemFromFile;

        while(!saveData.eof())
        {
            saveData >> itemFromFile;

            ItemType itemType = static_cast<ItemType>(itemFromFile);

            Item* item;
            if(itemType == healthPack)
            {
                item = new HealthPack();
            }
            else if(itemType == oxygenPack)
            {
                item = new OxygenPack();
            }
            player->inventory->addItem(item);
        }

        saveData.close();
    }
    else
    {
        cout << "Cannot load save data as none exists." << endl;
    }
}



void GameHelper::endGame(const Player* player)
{
    //If the player has a bad ship part, and they collected only four parts, they get the bad ending!
    if(player->inventory->getHasPhonyShipPart() && player->inventory->getNumOfShipParts() == 4)
    {
        ifstream badEndingText("./files/badEndingText.dat");
        string badEnding;
        getline(badEndingText, badEnding, '\n');
        L_StringHelper::printTextWrap(badEnding);
        cout << badEnding << endl;
    }
    else //the user gets the good ending!
    {
        ifstream goodEndingText("./files/goodEndingText.dat");
        string goodEnding;
        getline(goodEndingText, goodEnding, '\n');
        L_StringHelper::printTextWrap(goodEnding);
        cout << goodEnding << endl;
    }

    cout << "The end." << endl;
    exit(0);
}


void GameHelper::gameOver(string& deathMessage)
{
    L_StringHelper::printTextWrap(deathMessage);
    cout << deathMessage << endl;

    cout << "Press enter to end session." << endl;

    cin.ignore();
    cin.ignore( 500, '\n' );

    cout << "Thanks for playing!" << endl;
    exit(0);
}


void GameHelper::saveGame(const RoomManager* roomManager, const Player* player)
{
    cout << "Saving game..." << endl;

    ofstream saveData;
    saveData.open("./saveData.out");

    //write to the file the player's current room and how many moves they have left
    saveData << roomManager->getCurrentRoom() << endl;
    saveData << roomManager->getMovesLeft() << endl << endl;

    //write to the file the data in each of the game's rooms
    for(int i = 0; i < roomManager->getNumRooms(); i++)
    {
        const Room room(roomManager->getRoom(i));
        saveData << room.getRoomID() << endl;
        saveData << room.getNorthRoom() << " " << room.getEastRoom() << " " << room.getSouthRoom() << " " << room.getWestRoom() << endl;
        saveData << room.getRoomName() << endl;
        saveData << room.getCanEnemySpawnHere() << endl;
        saveData << room.getPuzzleID() << endl;
        saveData << room.getLockedRoom() << endl;
        saveData << room.getItemID() << endl;
        saveData << room.getNpcID() << endl;
        saveData << endl;
    }

    //Write the player's info to the file
    saveData << player->getHealth() << " " << player->getOxygen() << endl;

    saveData << player->inventory->getNumOfShipParts() << endl;
    saveData << player->inventory->getHasPhonyShipPart() << endl;
    if(!player->inventory->isEmpty())
    {
        for(int i = 0; i < player->inventory->getSize(); i++)
        {
            ItemType currentItemType = player->inventory->getItemTypeAtIndex(i);
            saveData << currentItemType << " ";
        }
    }
    saveData << endl;
    saveData.close();

    cout << "Save complete!" << endl << endl;
}
