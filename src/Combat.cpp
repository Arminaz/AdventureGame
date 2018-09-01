#include "Combat.h"
#include "CombatInterface.h"
#include "Exceptions.h"
#include <iostream>

using namespace std;

Combat::Combat(Player* p, Alien* a)
{
    if(p == nullptr || a == nullptr)
    {
        throw invalid_parameter("The objects passed to combat are uninitialized.");
    }
    player = p;
    enemy = a;
}


bool Combat::fight()
{
    //check first to see if the player or the enemy is already dead.
    player->checkCurrentStatus();
    enemy->checkCurrentStatus();

    if(enemy->isCharDead())
    {
        return true;
    }
    if(player->isCharDead())
    {
        return false;
    }

    //create a new interface to handle input from user...
    Interface* combatInterface = new CombatInterface();

    PlayerChoices playerChoice;
    isCombatActive = true;

    //Do this loop while both characters are alive
    while(isCombatActive)
    {
        printStats();

        //do this only if the player is not dead
        if(!player->isCharDead())
        {
            playerChoice = combatInterface->getInput();

            playerTurn(playerChoice);

            //Check to see if the enemy has died and adjust the value of their isDead booleon accordingly
            enemy->checkCurrentStatus();
        }
        else
        {
            delete combatInterface;

            //the player has died, so return false
            return false;
        }

        //Do this only if the enemy is not dead
        if(!enemy->isCharDead())
        {
            enemyTurn(playerChoice);

            player->checkCurrentStatus();
        }
        else
        {
            delete combatInterface;

            //the player has won the battle, so return true
            return true;
        }
    }
    return false;
}

void Combat::playerTurn(PlayerChoices playerChoice)
{
    if(playerChoice == attack)
    {
        //deal damage to the enemy
        cout << "You attack, dealing " << player->getDamage() << " damage!" << endl;
        enemy->setHealth(enemy->getHealth() - player->getDamage());
    }
    else if(playerChoice == useItem)
    {
        player->useItem();
    }
}

void Combat::enemyTurn(PlayerChoices playerChoice)
{
    if(playerChoice == defend)
    {
        cout << "You defend." << endl;
        //the conditional checks if the enemy's damage minus player's defence would be negative, because then we would be adding to the player's health
        int enemyDamage = enemy->getDamage() / 2;
        cout << "The alien swipes at you, dealing " << enemyDamage << " damage." << endl;
        player->setHealth(player->getHealth() - enemyDamage);
    }
    else
    {
        player->setHealth(player->getHealth() - enemy->getDamage());
        cout << "The alien swipes at you, dealing " << enemy->getDamage() << " damage." << endl;
    }
}



void Combat::printStats() const
{
    cout << "\nYour health: " << player->getHealth() << endl;
    cout << "Alien's health: " << enemy->getHealth() << endl;
}
