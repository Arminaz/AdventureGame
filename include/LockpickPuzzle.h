#ifndef LOCKPICKPUZZLE_H
#define LOCKPICKPUZZLE_H

#include "Puzzle.h"

#include <string>
#include <iostream>

/**
*@file LockpickPuzzle.h
*@brief Class that defines a puzzle where the user
*@brief user must correctly guess a sequence of three numbers without given any clues.
*@author
*/

class LockpickPuzzle : public Puzzle
{
    public:
        /**
        *@brief LockpickPuzzle constructor
        */
        LockpickPuzzle();

        virtual ~LockpickPuzzle() {}

        /**
        *@brief Puzzle Operator method.
        *@brief This is where the player does the puzzle.
        *@return bool true if successfull, false if not sucessfull
        */
        virtual bool doPuzzle();

    protected:

    private:
        /**
        *@brief Puzzle get help method.
        *@brief This is where the player can get help about the specific puzzle.
        */
        virtual void getHelp() const;
};

#endif // LOCKPICKPUZZLE_H
