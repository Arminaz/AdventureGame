#include "Weapon.h"

Weapon::Weapon(int damage)
    : weaponDamage(damage)
{
    itemName = "Weapon";
    type = weapon;
}

ItemType Weapon::useItem()
{
    return type;
}

int Weapon::getWeaponDamage() const
{
    return weaponDamage;
}
