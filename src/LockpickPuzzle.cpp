#include "LockpickPuzzle.h"
#include "L_StringHelper.h"
#include <cstdlib>

using namespace std;

LockpickPuzzle::LockpickPuzzle()
{
    //ctor
}

bool LockpickPuzzle::doPuzzle()
{
    if(isCompleted)
    {
        cout << "You have already hacked this terminal." << endl;
        return true;
    }

    bool answerFound = false;
    string userInput = "";

    int answer = rand() % 899 + 100;

    int dissectAnswer = answer;
    int* answerDigits = new int[3];

    //get each individual answer into the answerDigits array
    for(int i = 2; i >= 0; i--)
    {
        answerDigits[i] = dissectAnswer % 10;
        dissectAnswer /= 10;
    }

    while (lives!=0)
    {
        cout << "Complete the Lockpick Puzzle" << endl;
        cout << "Type 'H' in the input field to get help at anytime!" << endl;
        cout << "Total lives left: " << lives << endl;

        userInput = getInput();

        if(userInput == "h")
        {
            this->getHelp();
        }
        else if(L_StringHelper::toInt(userInput) == answer)
        {
            answerFound = true;
            break;
        }
        else
        {
            int number = L_StringHelper::toInt(userInput);
            int* inputValue = new int[3];

            //dissect the user's input
            for(int i = 2; i >= 0; i--)
            {
                inputValue[i] = number % 10;
                number /= 10;
            }
            bool correctDigitExists = false;

            //check if each value of the user input matches with one of the digits in the answer
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(inputValue[i] == answerDigits[j])
                    {
                        cout << inputValue[i] << " ";
                        inputValue[i] = -1;
                        correctDigitExists = true;
                    }
                }
            }

            if(correctDigitExists)
            {
                cout << "is correct." << endl;
            }
            else
            {
                cout << "No correct digit provided." << endl;
            }

            wrongGuess();
            lives--;
            delete []inputValue;
        }
    }
    delete []answerDigits;
    if(answerFound)
    {
        isCompleted = true;
        cout << "You successfully hacked the terminal!" << endl;
        return true;
    }

    return false;
}

void LockpickPuzzle::getHelp() const
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t Help: Lockpick Puzzle" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "1) Type 3 digits (0-9).." << endl;
    cout << "2) With any correct digit on right spot, you will be informed." << endl;
    cout << "3) For example, you choose 123 and correct code was 126" << endl;
    cout << "\tyou will be informed that 1 2 is correct." << endl;
    cout << "4) Tip: Note: Position of correct digit won't be displayed." << endl;
    cout << "4) Tip: Try different digits on different positions." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << endl;
}
