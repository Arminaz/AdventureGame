/**
*@file Item.h
*@brief Base class for all items in the game.
*@author
*/

#ifndef ITEM_H
#define ITEM_H

#include <string>

enum ItemType {healthPack, oxygenPack, weapon, shipPart, nullItem};

class Item
{
    public:
        /**
        *@brief constructor.
        */
        Item();

        /**
        *@brief item's destructor.
        */
        virtual ~Item() {}

        virtual ItemType useItem() = 0;

        /**
        *@brief prints this item's name to the screen.
        *@return the name of this item.
        */
        std::string printItemName() const;

        /**
        *@return the itemType of this item.
        */
        ItemType getItemType() const;

    protected:
        std::string itemName;
        ItemType type;

    private:
};

#endif // ITEM_H
