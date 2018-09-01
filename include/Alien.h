#ifndef ALIEN_H
#define ALIEN_H

#include "ImportantCharacter.h"

/**
*@file Alien.h
*@brief Class that servers as main object for the alien class
*@author
*/
class Alien : public ImportantCharacter
{
    public:
        /**
        *@brief Alien constructor
        *@brief it initalizes the alien object with health(h) and damage(d)
        *@param hp the hp of this enemy alien
        *@param dam the damage this enemy alien does
        */
        Alien(int hp = 25, int dam = 5);

        /**
        *@brief Alien destructor
        */
        virtual ~Alien() {}

        /**
        *@brief Checks alien current status
        */
        void checkCurrentStatus();

    protected:

    private:
};

#endif // ALIEN_H
