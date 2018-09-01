#ifndef CHARACTER_H
#define CHARACTER_H

/**
*@file Character.h
*@brief Class that serves as a superclass to all character classes.
*@author
*/
class Character
{
    public:
        /**
        *@brief Character constructor
        */
        Character();

        /**
        *@brief Character destructor
        */
        virtual ~Character() = 0;

        /**
        *@brief Checks if character is dead
        *@return isDead
        */
        virtual bool isCharDead();

        /**
        *@brief Sets Character dead or not
        *@param dead sets this character's dead status
        */
        virtual void setCharDead(bool dead);

    protected:

    private:
        bool isDead;

};

#endif // CHARACTER_H
