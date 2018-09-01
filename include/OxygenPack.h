/**
*@file OxygenPack.h
*@brief Item that restores all oxygen to the player.
*@author
*/


#ifndef OXYGENPACK_H
#define OXYGENPACK_H

#include "Item.h"

class OxygenPack : public Item
{

    public:
        /**
        *@brief constructor.
        */
        OxygenPack();

        /**
        *@brief OxygenPack's destructor.
        */
        virtual ~OxygenPack() {}

        /**
        *@brief uses this item by returning the itemType.
        *@return the type of this item.
        */
        virtual ItemType useItem();

    protected:

    private:

};

#endif // OXYGENPACK_H
