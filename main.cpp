#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Exceptions.h"
#include "Player.h"
#include "RoomManager.h"
#include "GameHelper.h"
#include "Interface.h"
#include "NewGameInterface.h"
#include "Inventory.h"
#include "Item.h"
#include "HealthPack.h"
#include "OxygenPack.h"
#include "ShipPart.h"

using namespace std;

int main()
{
    srand(time(0));

    cout << "WELCOME TO LEXINGTON!" << endl;

    Player* player = nullptr;

    RoomManager* game = nullptr;

    NewGameInterface* startGame = new NewGameInterface();
    PlayerChoices input;

    do
    {
        input = startGame->getInput();
        if(input == newGame)
        {
            //create a new player and a new set of rooms
            player = new Player(100, 10, 100);
            game = new RoomManager();

            GameHelper::newGame();
        }
        else if(input == loadGame)
        {
            GameHelper::loadGame(player, game);
        }
    }
    while(input != quitGame && game == nullptr);

    delete startGame;

    if(game != nullptr)
    {
        game->moveThroughRooms(player);
    }

    cout << "Thanks for playing!" << endl;

    delete game;
    delete player;

    return 0;
}
