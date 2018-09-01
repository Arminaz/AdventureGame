/**
*@file Inventory.h
*@brief Array of items that are stored for the player to use.
*@author
*/

#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include "Weapon.h"


/**
*Class localizing all items the player can use and storing them in an array.
*/

class Inventory
{
    public:
        /**
        *@brief Creates a new inventory with size set to 0.
        *@param startWeapon the weapon that the player starts with.
        */
        Inventory(Weapon* startWeapon);

        /**
        *@brief Deletes itemArray.
        */
        ~Inventory();

        /**
        *@brief adds item to the inventory.
        *@param itemToAdd the item being added to the inventory.
        */
        void addItem(Item* itemToAdd);

        /**
        *@brief use the item at the index provided.
        *@param itemNum the index of the item that is being used.
        */
        ItemType useItem(int itemNum);

        /**
        *@brief displays a list of all items currently in the itemArray.
        */
        void listItems();

        /**
        *@return the weapon this inventory contains.
        */
        Weapon getWeapon() const;

        /**
        *@return size, the number of items currently in the inventory.
        */
        int getSize() const;

        /**
        *@return numOfShipParts, the number of ship parts the user has collected so far.
        */
        int getNumOfShipParts() const;

        /**
        *@param index the index of the item we want to access.
        *@return the item type of the item at the specified index.
        */
        ItemType getItemTypeAtIndex(int index) const;

        /**
        *@return True if the inventory has no items in it (ie. size == 0), otherwise returns false.
        */
        bool isEmpty() const;

        /**
        *@return whether the player has a phony ship part or not.
        */
        bool getHasPhonyShipPart() const;

        /**
        *@param newValue the new truth value for hasPhonyShipPart.
        */
        void setHasPhonyShipPart(bool newValue);

    protected:

    private:
        int size;
        Weapon* gun;
        Item *itemArray[10];

        int numOfShipParts;

        bool hasPhonyShipPart;

};

#endif // INVENTORY_H
