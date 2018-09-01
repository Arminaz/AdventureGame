#ifndef IMPORTANTCHARACTER_H
#define IMPORTANTCHARACTER_H

#include "Character.h"
#include "Inventory.h"

/**
*@file ImportantCharacter.h
*@brief Class serves as important who have direct relation to the game
*@brief Player or Alien character
*@author
*/
class ImportantCharacter : public Character
{
    public:
        /**
        *@brief ImportantCharacter constructor
        *@brief Gives health and damage to the character
        *@param hp the hp of this character
        *@param dam the damage this character does
        *@throw invalid_parameter if health or damage is lower than 0
        *@throw
        */
        ImportantCharacter(int hp = 50, int dam = 1);

        /**
        *@brief ImportantCharacter destructor
        */
        virtual ~ImportantCharacter();

        /**
        *@brief Gets Character's max health
        *@return max health this player can have
        */
        int getMaxHealth() const;

        /**
        *@brief Gets character's health
        *@return health of this character
        */
        virtual int getHealth() const;

        /**
        *@brief Sets Character's health
        *@param newHealth the new health value for this character
        */
        virtual void setHealth(int newHealth);


        /**
        *@brief Gets Character's damage
        *@return damage value of this character
        */
        int getDamage() const;

        virtual void checkCurrentStatus() = 0;

        Inventory* inventory;
    protected:

    private:
        int health;
        int maxHealth;

};

#endif // IMPORTANTCHARACTER_H
