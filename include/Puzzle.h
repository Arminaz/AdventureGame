#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include <map>

/**
*@file Puzzle.h
*@brief Class that serves as a superclass to all puzzles
*@author
*/
class Puzzle
{
    public:
        /**
        *@brief Puzzle constructor
        */
        Puzzle();

        /**
        *@brief Puzzle destructor
        */
        virtual ~Puzzle(){}

        virtual bool doPuzzle() = 0;

        /**
        *@brief Checks completion which is true if the puzzle has been solved, false if it has not been.
        *@return bool isCompleted.
        */
        bool getCompletionStatus() const;

    protected:
        int lives;
        bool isCompleted;

        /**
        *@brief Checks the length of the word for the puzzle.
        *@param word the word to check its length against
        *@param size the size word must be >= to.
        *@return bool length
        */
        bool checkLength(std::string word, int size=3);

        /**
        *@brief Gets user input for the puzzle.
        *@return input from the user.
        */
        std::string getInput();

        /**
        *@brief Wrong guess function.
        */
        void wrongGuess();
        virtual void getHelp() const = 0;
    private:

};

#endif // PUZZLE_H
