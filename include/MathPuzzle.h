#ifndef MATHPUZZLE_H
#define MATHPUZZLE_H

#include "Puzzle.h"

#include <string>

/**
*@file MathPuzzle.h
*@brief Class that Defines a puzzle where the user must solve a simple math problem.
*@author
*/

class MathPuzzle : public Puzzle
{
    public:
        /**
        *@brief MathPuzzle constructor, that takes in string answer for the puzzle.
        *@param ans the answer to the puzzle
        *@todo Need to throw an exception if answer is anything but digits.
        */
        MathPuzzle(std::string ans);

        virtual ~MathPuzzle() {}

        /**
        *@brief Puzzle Operator method.
        *@brief This is where the player does the puzzle.
        *@return true if successfull, false if not sucessfull
        */
        virtual bool doPuzzle();

    protected:

    private:
        /**
        *@brief Puzzle get help method.
        *@brief This is where the player can get help about the specific puzzle.
        */
        void getHelp() const;

        std::string answer;
};

#endif // MATHPUZZLE_H
