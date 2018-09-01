#include "RoomManager.h"
#include "Interface.h"
#include "RoomInterface.h"
#include "Exceptions.h"
#include "GameHelper.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
//#incldue <string>

using namespace std;

RoomManager::RoomManager()
    : numOfRooms(25), currentRoom(24), movesLeft(150)
{
    //create an array of Rooms...
    gameMap = new Room[numOfRooms];

    ifstream inputRoomData;
    inputRoomData.open("./files/roomData.dat");

    ifstream inputRoomDescriptions("./files/roomDescriptions.dat");

    //Get data from input file and put that info in each room
    for(int i = 0; i < numOfRooms; i++)
    {
        try
        {
            gameMap[i].getRoomInfo(inputRoomData, inputRoomDescriptions);
        }
        catch(invalid_input& err)
        {
            //since we cannot initialize the rooms with the corrupted data, terminate the program
            cout << err.what() << endl;
            cout << "Cannot read data from file." << endl;
            cout << "Exiting..." << endl;
            exit(0);
        }
    }
    inputRoomData.close();
    inputRoomDescriptions.close();
}

RoomManager::RoomManager(ifstream& inputFile)
{
    numOfRooms = 25;
    gameMap = new Room[numOfRooms];

    inputFile >> currentRoom;
    inputFile >> movesLeft;

    ifstream inputRoomDescriptions("./files/roomDescriptions.dat");

    //Get data from input file and put that info in each room
    for(int i = 0; i < numOfRooms; i++)
    {
        try
        {
            gameMap[i].getRoomInfo(inputFile, inputRoomDescriptions);
        }
        catch(invalid_input& err)
        {
            //since we cannot initialize the rooms with the corrupted data, terminate the program
            cout << err.what() << endl;
            cout << "Cannot read data from file." << endl;
            cout << "Exiting..." << endl;
            exit(0);
        }
    }

    if(!inputFile)
    {
        throw invalid_input("Cannot read data from inputFile.");
    }
}

RoomManager::~RoomManager()
{
    delete []gameMap;
}

void RoomManager::moveThroughRooms(Player* player)
{
    bool hasFourParts = false;
    bool isPlaying = true;

    while(isPlaying)
    {
        movesLeft--;

        //if the player runs out of moves, then they die!
        if(movesLeft <= 0)
        {
            //this is death by running out of moves
            ifstream text("./files/puzzleDeath");
            string deathMessage;
            getline(text, deathMessage, '\n');

            GameHelper::gameOver(deathMessage);
        }

        bool stillInRoom = true;
        gameMap[currentRoom].enterRoom(player);

        while(stillInRoom)
        {
            try
            {
                //if the player has four parts, prompt them to return to the ship.
                if(player->inventory->getNumOfShipParts() == 4 && !hasFourParts)
                {
                    hasFourParts = true;
                    cout << "You have collected enough ship parts. Would you like to continue exploring? [Y/N] ";
                    char input;
                    cin >> input;
                    if(input == 'n')
                    {
                        GameHelper::endGame(player);
                    }
                }

                //if the player has all five parts, take them to the endgame.
                if(player->inventory->getNumOfShipParts() == 5)
                {
                    cout << "You have collected all the parts. Returning to the Lexington..." << endl;
                    GameHelper::endGame(player);
                }

                Interface* roomInterface = new RoomInterface(&gameMap[currentRoom]);
                PlayerChoices playerInput = roomInterface->getInput();

                delete roomInterface;

                    //if statements to determine what to do with the user input
                if(playerInput == examine)
                {
                    gameMap[currentRoom].examineRoom(player);
                }
                else if(playerInput == playPuzzle)
                {
                    gameMap[currentRoom].playPuzzle();
                }
                else if(playerInput == useItem)
                {
                    player->useItem();
                }
                else if(playerInput == talk)
                {
                    gameMap[currentRoom].talkToNpc();
                }
                else if(playerInput == saveGame)
                {
                    GameHelper::saveGame(this, player);
                }
                else if(playerInput == quitGame)
                {
                    stillInRoom = false;
                    isPlaying = false;
                }
                else
                {
                    //check if one of the rooms is locked, and if the player tries to go that way, stop them!
                    if(gameMap[currentRoom].getLockedRoom() == playerInput)
                    {
                        cout << "A metal door blocks your way; you cannot go past it." << endl;
                    }
                    else
                    {
                        int nextRoom = getNextRoom(playerInput);
                        nextRoom = (nextRoom == -1) ? throw invalid_index("You cannot go that way.") : nextRoom;

                        currentRoom = nextRoom;
                        stillInRoom = false;
                    }
                }

            }
            catch(invalid_index& err)
            {
                cout << err.what() << endl;
            }
            catch(invalid_input& err)
            {
                cout << err.what() << endl;
            }
        }
    }
}

Room& RoomManager::getRoom(int index) const
{
    if(index < 0 || index >= numOfRooms)
    {
        throw invalid_index("Cannot access that location in the gameMap.");
    }
    return this->gameMap[index];
}

int RoomManager::getNumRooms() const
{
    return this->numOfRooms;
}

int RoomManager::getCurrentRoom() const
{
    return currentRoom;
}

int RoomManager::getMovesLeft() const
{
    return movesLeft;
}


int RoomManager::getNextRoom(PlayerChoices& playerInput) const
{
    //Get the next index for the room depending on the input from the player
    switch(playerInput)
    {
        case moveNorth : return gameMap[currentRoom].getNorthRoom(); break;
        case moveEast : return gameMap[currentRoom].getEastRoom(); break;
        case moveSouth : return gameMap[currentRoom].getSouthRoom(); break;
        case moveWest : return gameMap[currentRoom].getWestRoom(); break;
        default : return -1; break;
    }
    return -1;
}
