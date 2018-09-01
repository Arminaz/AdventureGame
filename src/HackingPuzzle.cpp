#include "HackingPuzzle.h"
#include "L_StringHelper.h"

#include <cmath>
#include <cstdlib>

using namespace std;

HackingPuzzle::HackingPuzzle()
    : numAnswers(8)
{
}

bool HackingPuzzle::doPuzzle()
{
    if(isCompleted)
    {
        cout << "You have already hacked this terminal." << endl;
        return true;
    }

    int* listOfNumbers = new int[numAnswers];
    int answerIndex = rand() % numAnswers;
    answerIndex = answerIndex == 0 ? 3 : answerIndex; // if the answer is going to be in the first spot, change it to the third spot instead
    bool answerFound = false;
    string userInput = "";
    int answer = 0;

    //get random numbers for the eight potential answers.
    for(int i=0; i<numAnswers; i++)
    {
       if(i==answerIndex) //if i equals the index of the answer, then put the answer in this location!
       {
           for(int j = 0; j < 4; j++)
           {
                answer += (rand() % 7 + 1) * pow(10, j);
           }
           listOfNumbers[i] = answer;
       }
       else
       {
           int decoy = 0;
           for(int j = 0; j < 4; j++)
           {
               decoy += (rand() % 7 + 1) * pow(10, j);
           }
           listOfNumbers[i] = decoy;
       }
    }

    //get all the digits of the answers so that it is easy to check how many digits the player guessed were right
    int dissectAnswer = answer;
    int* answerDigits = new int[4];

    for(int i = 3; i >= 0; i--)
    {
        answerDigits[i] = dissectAnswer % 10;
        dissectAnswer /= 10;
    }

    //let the user guess the correct answer, while their lives are > 0
    while(lives!=0)
    {
        cout << "Complete the Hack Puzzle" << endl;
        cout << "Type 'H' in the input field to get help at anytime!" << endl;
        cout << "Total lives left: " << lives << endl;
        cout << endl;

        for(int i = 0; i < numAnswers; i++)
        {
            cout << listOfNumbers[i] << endl;
        }
        userInput = getInput();

        if(userInput == "h")
        {
            getHelp();
        }
        else if(L_StringHelper::toInt(userInput) == answer)
        {
            answerFound = true;
            break;
        }
        else
        {
            int number = L_StringHelper::toInt(userInput);

            int correct = 0;
            int* inputValues = new int[4];

            //assign the user's input to the array inputValues
            for(int i = 3; i >= 0; i--)
            {
                inputValues[i] = number % 10;
                number /= 10;
            }
            //check if any of the digits correctly match that of the answer
            for(int i = 0; i < 4; i++)
            {
                if(inputValues[i] == answerDigits[i])
                {
                    correct++;
                }
            }

            cout << "Info: " << correct << "/4 correct, try again." << endl;

            if(lives!=0)
            {
                wrongGuess();
            }
            lives--;
            delete []inputValues;
        }
    }

    delete []answerDigits;
    delete []listOfNumbers;

    if(answerFound) //the user found the answer, so return true!
    {
        isCompleted = true;
        cout << "You successfully hacked the terminal!" << endl;
        return true;
    }

    return false; //the user failed to find the answer.
}

void HackingPuzzle::getHelp() const
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t Help: Hack Puzzle" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "1) You have been provided with possible codes." << endl;
    cout << "2) With each wrong guess, you will be told how correct were you." << endl;
    cout << "3) For example, you choose 3221 and correct code was 3111" << endl;
    cout << "\tyou will be informed that you were correct 2/4." << endl;
    cout << "4) Tip: Use your lives wisely." << endl;
    cout << "5) Tip: You are welcome to experiment with codes not listed.." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << endl;
}
