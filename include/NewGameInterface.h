/**
*@file NewGameInterface.h
*@brief Handles input for a new game.
*@author
*/

#ifndef NEWGAMEINTERFACE_H
#define NEWGAMEINTERFACE_H

#include "Interface.h"
#include <string>

class NewGameInterface : public Interface
{
    public:
        NewGameInterface();

        void getHelp();

    protected:

    private:
};

#endif // NEWGAMEINTERFACE_H
