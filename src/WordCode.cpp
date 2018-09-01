#include "WordCode.h"
#include "Exceptions.h"

using namespace std;

WordCode::WordCode(string ans)
{
    answer = ans;
    if(answer.length() < 3)
        throw invalid_parameter("Answer must contain at least 3 characteres!");
}


bool WordCode::doPuzzle()
{
    if(isCompleted)
    {
        cout << "You have already hacked this terminal." << endl;
        return true;
    }

    bool answerFound = false;
    string userInput = "";
    int aSize = answer.size();
    string codeAnswer = "";
    L_StringHelper::toLower(answer);

    //do this only if the answer is greater than three characters!
    if(checkLength(answer))
    {
        map <string, string> wordMap;
        initializeWordMap(wordMap);

        //make the entire answer in lowercase, then get the corresponding element from the word map and assign that to codeAnswer
        for(int i=0; i<=aSize; i++)
        {
            string lowerAnswer = answer;
            L_StringHelper::toLower(lowerAnswer);
            string element;
            element.push_back(lowerAnswer[i]);
            if(wordMap.count(element))
            {
                codeAnswer += wordMap.find(element)->second;
            }
        }

        while(lives!=0)
        {
            cout << "Word Code Puzzle" << endl;
            cout << "Type 'H' in the input field to get help at anytime!" << endl;
            cout << "Type 'C' in the input field to get alien code at anytime!" << endl;
            cout << "Type the password: " << codeAnswer << " in english word" << endl;
            cout << "Total lives left: " << lives << endl;

            userInput = getInput();
            if(userInput == "h")
            {
                this->getHelp();
            }
            else if(userInput== "c") //print the translation sheet, which details all the combinations
            {
                cout << "----------------------------------------------------------------" << endl;
                cout << "\t\t Alien Code Translation Sheet" << endl;
                cout << "----------------------------------------------------------------" << endl;
                cout << "\tLetter\tAlien Code";
                cout << "\tLetter\tAlien Code" << endl;
                cout << "----------------------------------------------------------------" << endl;
                int i=0;
                map <string, string> :: iterator itr;
                for (itr = wordMap.begin(); itr != wordMap.end(); ++itr)
                {
                    i++;
                    cout << '\t' << itr->first
                         << '\t' << itr->second;
                    if(i%2==0)
                    {
                        cout << endl;
                    }
                    else
                    {
                        cout << "\t";
                    }
                }
                cout << "----------------------------------------------------------------" << endl;
                cout << "Press enter to continue";
                cin.ignore();
                cin.ignore(500, '\n');
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
    }
    else
    {
        throw invalid_parameter("Answer must contain at least 3 characteres!");
    }
    return false;
}


void WordCode::getHelp() const
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t Help: Word Code Puzzle" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "1) You know the password to a terminal, you just need to convert" << endl;
    cout << "\tit." << endl;
    cout << "2) For example, if the password is: :~%&2&P)4P)4$#2{[(%@V\"-/" << endl;
    cout << "\tthe code would be: Password" << endl;
    cout << "3) It is recommended to write the code somewhere to get it right" << endl;
    cout << "4) Tip: The code is not case sensitive" << endl;
    cout << "5) Type 'C' to view the alien language alphabetically" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << endl;
}


void WordCode::initializeWordMap(map<string, string>& wordMap)
{
    //assign each letter with a pairing string of random letters
    wordMap.insert(pair <string, string> ("a", "&2&"));
    wordMap.insert(pair <string, string> ("b", "(28;"));
    wordMap.insert(pair <string, string> ("c", "#-2"));
    wordMap.insert(pair <string, string> ("d", "\"-/"));
    wordMap.insert(pair <string, string> ("e", "?']"));
    wordMap.insert(pair <string, string> ("f", "^K1"));
    wordMap.insert(pair <string, string> ("g", "-!@"));
    wordMap.insert(pair <string, string> ("h", "|}`"));
    wordMap.insert(pair <string, string> ("i", "*@M"));
    wordMap.insert(pair <string, string> ("j", "O!L"));
    wordMap.insert(pair <string, string> ("k", "@$$"));
    wordMap.insert(pair <string, string> ("l", ">.<"));
    wordMap.insert(pair <string, string> ("m", "-_-"));
    wordMap.insert(pair <string, string> ("n", "-.-"));
    wordMap.insert(pair <string, string> ("o", "{[("));
    wordMap.insert(pair <string, string> ("p", ":~%"));
    wordMap.insert(pair <string, string> ("q", "!@#"));
    wordMap.insert(pair <string, string> ("r", "%@V"));
    wordMap.insert(pair <string, string> ("s", "P)4"));
    wordMap.insert(pair <string, string> ("t", "^7^"));
    wordMap.insert(pair <string, string> ("u", "<^>"));
    wordMap.insert(pair <string, string> ("v", "<V>"));
    wordMap.insert(pair <string, string> ("w", "$#2"));
    wordMap.insert(pair <string, string> ("x", "62/"));
    wordMap.insert(pair <string, string> ("y", "/-\\"));
    wordMap.insert(pair <string, string> ("z", "||Z"));
}
