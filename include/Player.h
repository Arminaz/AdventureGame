#ifndef PLAYER_H
#define PLAYER_H

#include "ImportantCharacter.h"

/**
*@file Player.h
*@brief Class that servers as main object for the playable character
*@author
*/
class Player : public ImportantCharacter
{
    public:
        /**
        *@brief Player constructor
        *@brief initalizes the player object with health(h) damage(d) and oxygen(o)
        *@param hp the amount of health for this player
        *@param dam the amount of damage this player does
        *@param oxy the amount of oxygen this player has
        *@throw invalid_parameter if oxygen is lower than 0.
        */
        Player(int hp = 100, int dam = 10, int oxy = 100);

        /**
        *@brief Player Destructor
        */
        virtual ~Player() {}

        /**
        *@brief Gets the max level of oxygen of the player.
        *@return int maxOxygen
        */
        int getMaxOxygen() const;

        /**
        *@brief Gets the oxygen level of the player.
        *@return int oxygen
        */
        int getOxygen() const;

        /**
        *@brief Sets the new oxygen level for the player.
        *@param newOxygen
        */
        void setOxygen(int newOxygen);

        /**
        *@brief Checks if player has 0 health or 0 oxygen, then sets player to dead
        */
        void checkCurrentStatus();


        /**
        *@brief gets the input from the user pertaining to which item they want to use.
        *@throw invalid_input if the user input is not valid.
        */
        void useItem();

    protected:
        int oxygen;
        int maxOxygen;

    private:
};

#endif // PLAYER_H
