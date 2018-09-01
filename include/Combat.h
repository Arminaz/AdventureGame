/**
*@file Combat.h
*@brief Handles combat.
*@author
*/

#ifndef COMBAT_H
#define COMBAT_H

#include "Player.h"
#include "Alien.h"
#include "Interface.h"


/**
*Class simulating combat between two Character objects.
*This is usually done between a player character and an enemy character.
*/

class Combat
{
    public:
        /**
        *@param p the player character
        *@param a the alien character
        *@throws invalid_parameter if one of the two pointers are null
        */
        Combat(Player* p, Alien* a);

        /**
        *@return true if player wins the fight
        *@return false if player loses the fight
        */
        bool fight();

        /**
        *@brief handles input during player's turn.
        *@param the choice of the player this turn.
        */
        void playerTurn(PlayerChoices playerChoice);

        /**
        *@brief handles the enemy's turn.
        *@param the choice of the player this turn.
        */
        void enemyTurn(PlayerChoices playerChoice);

        /**
        *@brief displays the player's health and the enemy's health.
        */
        void printStats() const;

    protected:

    private:
        Player* player;
        Alien* enemy;
        bool isCombatActive;
};

#endif // COMBAT_H
