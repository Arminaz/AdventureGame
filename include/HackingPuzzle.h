#ifndef HACKINGPUZZLE_H
#define HACKINGPUZZLE_H

#include "Puzzle.h"

#include <string>
#include <iostream>

/**
*@file HackingPuzzle.h
*@brief Class that Defines a puzzle where the user
*@brief must determine the correct sequence of numbers from a given list of potential answers.
*@author
*/
class HackingPuzzle : public Puzzle
{
    public:

        /**
        *@brief HackingPuzzle constructor
        */
        HackingPuzzle();

        virtual ~HackingPuzzle() {}

        /**
        *@brief Puzzle Operator method.
        *@brief This is where the player does the puzzle
        *@return true if successfull, false if not sucessfull
        */
        virtual bool doPuzzle();

    protected:

    private:
        /**
        *@brief Puzzle get help method.
        *@brief This is where the player can get help about the specific puzzle.
        */
        virtual void getHelp() const;
        int numAnswers;
};

#endif // HACKINGPUZZLE_H
