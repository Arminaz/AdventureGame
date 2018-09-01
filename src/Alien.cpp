#include "Alien.h"

Alien::Alien(int hp, int dam)
: ImportantCharacter(hp, dam)
{
}


void Alien::checkCurrentStatus()
{
    if(this->getHealth() <= 0)
    {
        this->setCharDead(true);
    }
}

