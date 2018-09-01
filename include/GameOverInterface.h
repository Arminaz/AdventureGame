/**
*@file GameOverInterface.h
*@brief Handles input when the player character has died.
*@author
*/

#ifndef GAMEOVERINTERFACE_H
#define GAMEOVERINTERFACE_H

#include "Interface.h"

#include <cstdlib>

class GameOverInterface : public Interface
{
    public:
        GameOverInterface();

        /**
        *@brief Displays a list of options available to the user.
        */
        void getHelp();
    protected:
    private:
};

#endif // GAMEOVERINTERFACE_H
