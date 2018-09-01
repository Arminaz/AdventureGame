#include "Puzzle.h"
#include "L_StringHelper.h"

#include <iostream>
#include <iterator>
#include <limits>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;


Puzzle::Puzzle()
    : lives(4), isCompleted(false)
    {}


bool Puzzle::checkLength(string word, int size)
{
    //check the length of the string against size
    int length = word.length();
    if(length >= size)
    {
        return true;
    }
    return false;
}

string Puzzle::getInput()
{
    //get input from the user
    string input;
    cout << "Enter your input: ";
    cin >> input;
    cout << endl;
    L_StringHelper::toLower(input);
    return input;
}

void Puzzle::wrongGuess()
{
    cout << "Wrong Guess, press enter to try again";
    cin.ignore();
    cin.ignore( 500, '\n' );
}


bool Puzzle::getCompletionStatus() const
{
    return isCompleted;
}
