#include "MathPuzzle.h"
#include "L_StringHelper.h"

#include <iostream>
#include <cstdlib>


using namespace std;

MathPuzzle::MathPuzzle(string ans)
    : answer(ans)
{
}

bool MathPuzzle::doPuzzle()
{
    if(isCompleted)
    {
        cout << "You have already hacked this terminal." << endl;
        return true;
    }

    bool answerFound = false;
    string userInput = "";
    int numbAnswer = L_StringHelper::toInt(answer);

    int randomProblem = rand() % 2 + 1;
    string problem = "";
    int operandOne, operandTwo;

    //determine which kind of problem the user is going to be given
    switch(randomProblem)
    {
        case 1 : //Add
            operandOne = numbAnswer/2;
            if(numbAnswer % 2 == 1)
            {
                operandTwo = operandOne + 1;
            }
            else
            {
                operandTwo = operandOne;
            }

            problem = L_StringHelper::toString(operandOne) + "+"
                    + L_StringHelper::toString(operandTwo) + "=";
            break;
        case 2 : //Subtract
            operandOne = numbAnswer*2;
            operandTwo = numbAnswer;
            problem = L_StringHelper::toString(operandOne) + "-"
                    + L_StringHelper::toString(operandTwo) + "=";
            break;

    }
    while(lives!=0)
    {
        cout << "Complete the math Puzzle" << endl;
        cout << "Type 'H' in the input field to get help at anytime!" << endl;
        cout << "Find the solution for " << problem << endl;
        cout << "Total lives left: " << lives << endl;

        userInput = getInput();

        if(userInput == "h")
        {
           this->getHelp();
        }
        else if(userInput == answer)
        {
           answerFound = true;
           break;
        }
        else
        {
           lives--;
           if(lives!=0)
           {
                wrongGuess();
           }
        }
    }

    if(answerFound)
    {
        isCompleted = true;
        cout << "You successfully hacked the terminal!" << endl;
        return true;
    }
    return false;
}


void MathPuzzle::getHelp() const
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t Help: Math Problem Puzzle" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "1) You have been provided with a math problem" << endl;
    cout << "2) You must find find solution to the math problem." << endl;
    cout << "3) For example, if the problem is 2+2, answer is 4." << endl;
    cout << "4) Tip: Do not overthink this puzzle, it's not meant to be hard." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << endl;
}
