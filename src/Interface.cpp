#include "Interface.h"
#include "Exceptions.h"

Interface::Interface()
{
    actionMap.insert(pair<char, PlayerChoices>('h', help));
}

PlayerChoices Interface::getInput()
{
    do
    {
        try
        {
            cout << "What do you do? ";
            cin >> userInput;

            if(!cin)
            {
                throw invalid_input("That is not valid input.");
            }

            userInput = tolower(userInput);

            //get the player's input in the action map and assign it to playerChoice
            PlayerChoices playerChoice = actionMap.at(userInput);

            clearInputStream(cin);

            if(playerChoice == help)
            {
                this->getHelp();
            }
            else
            {
                return playerChoice;
            }

        }
        catch(invalid_input& err)
        {
            //if the input stream is in a fail-state, the user ends up here.
            cerr << err.what() << endl << endl;
            clearInputStream(cin);
        }
        catch(out_of_range& err)
        {
            //if the input is not in the action map, the user ends up here.
            cout << "That is not valid input." << endl;
            clearInputStream(cin);
        }
    }
    while(true); //have this loop active until the user enters something valid and the funtion returns a value
}

void Interface::clearInputStream(istream& iStr)
{
    iStr.clear();
    iStr.ignore(500, '\n');
}
