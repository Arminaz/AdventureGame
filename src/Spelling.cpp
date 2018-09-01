#include "Spelling.h"
#include "Exceptions.h"
#include "L_StringHelper.h"

#include <iostream>

using namespace std;

Spelling::Spelling(string ans)
{
    if(ans.length() < 3)
    {
        throw invalid_parameter("Answer must contain at least 3 characteres!");
    }
    if(L_StringHelper::digitsExist(ans))
    {
        throw invalid_parameter("Spelling puzzle can not contain digits");
    }
    answer = ans;
    L_StringHelper::toLower(answer);
}

bool Spelling::doPuzzle()
{
    if(isCompleted)
    {
        cout << "You have already hacked this terminal." << endl;
        return true;
    }

    bool answerFound = false;
    string userInput = "";
    int aSize = answer.size();
    string spellWord = answer;

    //every three digits, enter a '_' character into the string
    for(int i=0; i<=aSize; i++)
    {
        if(i%3==0 && i!=0)
        {
            spellWord[i] = '_';
        }
    }

    while(lives!=0)
    {
        cout << "Complete the spelling Puzzle" << endl;
        cout << "Type 'H' in the input field to get help at anytime!" << endl;
        cout << "Complete the spelling for " << spellWord << endl;
        cout << "Total lives left: " << lives << endl;

        userInput = getInput();

        if(userInput == "h" || userInput == "H")
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


void Spelling::getHelp() const
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t Help: Spelling Puzzle" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "1) You know the full code already, you just need to type it." << endl;
    cout << "2) For example, if the code is: Pas_wor_, the complete code is:" << endl;
    cout << "\tPassword" << endl;
    cout << "3) Tip: Do not overthink this puzzle, it's not meant to be hard." << endl;
    cout << "4) Tip: The complete code is not case sensative!" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << endl;
}
