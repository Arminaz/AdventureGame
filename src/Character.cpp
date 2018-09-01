#include "Character.h"

Character::Character()
{
    this->isDead = false; //makes sure that character is not dead already.
}

Character::~Character()
{
    //Required for pure virtual destructor, making this class abstract
}

bool Character::isCharDead()
{
    return this->isDead;
}

void Character::setCharDead(bool dead)
{
    this->isDead = dead;
}


