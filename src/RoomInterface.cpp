#include "RoomInterface.h"
#include "Exceptions.h"

#include <iostream>
#include <ctype.h>

using namespace std;

RoomInterface::RoomInterface(Room* thisRoom)
    : currentRoom(thisRoom)
{
    //add all actions possible in a room to the actionMap.
    actionMap.insert(pair<char, PlayerChoices>('l', examine));
    actionMap.insert(pair<char, PlayerChoices>('n', moveNorth));
    actionMap.insert(pair<char, PlayerChoices>('e', moveEast));
    actionMap.insert(pair<char, PlayerChoices>('s', moveSouth));
    actionMap.insert(pair<char, PlayerChoices>('w', moveWest));
    actionMap.insert(pair<char, PlayerChoices>('t', playPuzzle));
    actionMap.insert(pair<char, PlayerChoices>('q', quitGame));
    actionMap.insert(pair<char, PlayerChoices>('1', saveGame));
    actionMap.insert(pair<char, PlayerChoices>('i', useItem));
    actionMap.insert(pair<char, PlayerChoices>('p', talk));
}

void RoomInterface::getHelp()
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t Help: Room" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Here are your options while in " << currentRoom->getRoomName() << endl;
    currentRoom->getNorthRoom() != -1 ? cout << "N: Move north." << endl : cout << '\0';
    currentRoom->getEastRoom() != -1 ? cout << "E: Move east." << endl : cout << '\0';
    currentRoom->getSouthRoom() != -1 ? cout << "S: Move south." << endl : cout << '\0';
    currentRoom->getWestRoom() != -1 ? cout << "W: Move west." << endl : cout << '\0';
    currentRoom->doesRoomHavePuzzle() ? cout << "T: Hack terminal." << endl : cout << '\0';
    currentRoom->doesRoomHaveNpc() ? cout << "P: Talk to your companion." << endl : cout << '\0';
    cout << "L: Examine the room." << endl;
    cout << "I: Use item." << endl;
    cout << "1: Save game." << endl;
    cout << "Q: Quit game." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\n";
}



