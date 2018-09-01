/**
*@file Weapon.h
*@brief Item that deals damage to another character.
*@author
*/


#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : Item
{
    public:
        /**
        *@brief creates a new weapon.
        *@param damage the amount of damage this weapon does.
        */
        Weapon(int damage);

        /**
        *@brief destructor.
        */
        virtual ~Weapon() {}

        /**
        *@brief uses this item by returning the itemType.
        *@return the type of this item.
        */
        virtual ItemType useItem();

        /**
        *@brief returns the value of weaponDamage.
        *@return the value of weaponDamage.
        */
        int getWeaponDamage() const;

    protected:

    private:
        int weaponDamage;
};

#endif // WEAPON_H
