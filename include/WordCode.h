#ifndef WORDCODE_H
#define WORDCODE_H

#include "Puzzle.h"
#include "L_StringHelper.h"

#include <map>
#include <string.h>
#include <iostream>

using namespace std;

/**
*@file WordCode.h
*@brief Class that defines a puzzle where the user must decipher a message written in symbols.
*@author
*/

class WordCode : public Puzzle
{
    public:
        /**
        *@brief WordCode constructor, that takes in string answer for the puzzle
        *@param ans the answer to the wordCode puzzle.
        *@throw invalid_parameter if answer contains < 3 characters.
        *@throw invalid_parameter if answer contains digits.
        *@todo Need to throw an exception if answer is anything but letters.
        */
        WordCode(string ans);

        virtual ~WordCode() {}

        /**
        *@brief Puzzle Operator method.
        *@brief This is where the player does the puzzle.
        *@return bool true if successful, false if not sucessful
        */
        virtual bool doPuzzle();

    protected:

    private:
        /**
        *@brief Word Code Puzzle, sets up code table for the player.
        */
        void initializeWordMap(map<string, string>& wordMap);

        /**
        *@brief Puzzle get help method.
        *@brief This is where the player can get help about the specific puzzle.
        */
        virtual void getHelp() const;

        string answer;
};

#endif // WORDCODE_H
