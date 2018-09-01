#include "HealthPack.h"


HealthPack::HealthPack()
{
    itemName = "Health Pack";
    type = healthPack;
}

ItemType HealthPack::useItem()
{
    return type;
}

