#include "Npc.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>

using namespace std;

Npc::Npc(ifstream& npcData)
{
    haveSpoken = false;

    npcData >> numOfStrings;

    dialog = new string[numOfStrings];

    //get a new line for each entry in the npc's dialogue
    for(int i = 0; i < numOfStrings; i++)
    {
        getline(npcData, dialog[i], '\n');

        npcData.ignore();
    }
}


void Npc::speak(){
    //print the dialogue to the screen
    if (haveSpoken == false){
        for(int i = 0; i < numOfStrings; i++){
            cout << dialog[i] << endl << endl;
        }
    }
    else{
        cout << "We have already spoken." << endl;
    }

    haveSpoken = true;
}


Npc::~Npc(){
    delete []dialog;
}
