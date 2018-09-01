/**
*@file HealthPack.h
*@brief Item that restores health to a character.
*@author
*/

#ifndef HEALTHPACK_H
#define HEALTHPACK_H

#include "Item.h"

class HealthPack : public Item
{

    public:
        /**
        *@brief HealthPack's constructor.
        */
        HealthPack();

        /**
        *@brief destructor.
        */
        virtual ~HealthPack() {}

        /**
        *@brief uses this item by returning the itemType.
        *@return the type of this item.
        */
        virtual ItemType useItem();

    protected:

    private:

};

#endif // HEALTHPACK_H
