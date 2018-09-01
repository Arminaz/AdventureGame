/**
*@file ShipPart.h
*@brief Represents the parts of the ship the user must collect.
*@author
*/

#ifndef SHIPPART_H
#define SHIPPART_H

#include "Item.h"

class ShipPart : public Item
{
    public:
        /**
        *@brief creates a new ShipPart item.
        *@param isPartPhony a bool representing if this part is phony or not.
        */
        ShipPart(bool isPartPhony);

        /**
        *@brief destructor.
        */
        virtual ~ShipPart() {}

        /**
        *@brief uses this item by returning the itemType.
        *@return the type of this item.
        */
        ItemType useItem();

        /**
        *@brief returns the value of the isThisPartPhony bool.
        *@return isThisPartPhony
        */
        bool isPartPhony() const;

    protected:

    private:
        /**
        *A bool variable representing if this part is a phony ship part.
        *If the user has four parts at the end of the game, and one is phony, they will lose the game.
        */
        bool isThisPartPhony;
};

#endif // SHIPPART_H
