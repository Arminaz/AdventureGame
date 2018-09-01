#include "ImportantCharacter.h"
#include "Exceptions.h"
#include "Weapon.h"

ImportantCharacter::ImportantCharacter(int hp, int dam)
{
    //Not calling character constructor, as it is implicitly called
    if(hp<1) //Health 0 would mean important character is already dead
    {
        throw invalid_parameter("Health can not be lower than 1");
    }
    if(dam<1) //Damage 0 would mean no gun is handy, while it is not the case at this time.
    {
        throw invalid_parameter("Damage can not be lower than 1");
    }

    this->maxHealth = hp;
    this->health = hp;

    Weapon* startWeapon = new Weapon(dam);

    this->inventory = new Inventory(startWeapon);
}

ImportantCharacter::~ImportantCharacter()
{
    delete inventory;
}


int ImportantCharacter::getHealth() const
{
    return this->health;
}

void ImportantCharacter::setHealth(int newHealth)
{
    if(newHealth > maxHealth)
    {
        health = maxHealth;
    }
    else
    {
        health = newHealth;
    }
}


int ImportantCharacter::getDamage() const
{
    Weapon weapon = this->inventory->getWeapon();
    return weapon.getWeaponDamage();
}


int ImportantCharacter::getMaxHealth() const
{
    return maxHealth;
}
