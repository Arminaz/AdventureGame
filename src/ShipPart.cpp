#include "ShipPart.h"

ShipPart::ShipPart(bool isPartPhony)
    :isThisPartPhony(isPartPhony)
{
    itemName = "Ship Part";
    type = shipPart;
}

ItemType ShipPart::useItem()
{
    return type;
}

bool ShipPart::isPartPhony() const
{
    return isThisPartPhony;
}
