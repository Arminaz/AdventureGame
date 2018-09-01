/**
*@file CombatInterface.h
*@brief Handles input relating to combat.
*@author
*/

#ifndef COMBATINTERFACE_H
#define COMBATINTERFACE_H

#include "Interface.h"
#include <iostream>


/**
*Class handling input relating to options available to user during combat.
*/

class CombatInterface : public Interface
{
    public:
        CombatInterface();
        virtual ~CombatInterface() {}

        virtual void getHelp();
    protected:
    private:
};
#endif // COMBATINTERFACE_H
