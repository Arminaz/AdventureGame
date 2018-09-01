#include "OxygenPack.h"


OxygenPack::OxygenPack()
{
    itemName = "Oxygen Pack";
    type = oxygenPack;
}

ItemType OxygenPack::useItem()
{
    return type;
}

