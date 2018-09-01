#ifndef SPELLING_H
#define SPELLING_H

#include "Puzzle.h"

#include <string>

using namespace std;

/**
*@file Spelling.h
*@brief Class that defines a puzzle where the user must fill in the blanks on a given word.
*@author
*/

class Spelling : public Puzzle
{
    public:
        /**
        *@brief Spelling constructor, that takes in string answer for the puzzle
        *@param ans the answer to the string puzzle
        *@throw invalid_parameter if answer contains < 3 characters.
        *@throw invalid_parameter if answer contains digits
        *@todo Need to throw an exception if answer is anything but letters.
        */
        Spelling(string ans);

        virtual ~Spelling() {}

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
        string answer;
};

#endif // SPELLING_H
