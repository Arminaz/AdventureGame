#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Exceptions.h"

#include <iostream>

using namespace std;

Player::Player(int hp, int dam, int oxy)
: ImportantCharacter(hp, dam)
{
    if(oxy<1)
    {
        throw invalid_parameter("Oxygen cannot be lower than 1"); //This means the character is already dead.
    }
    maxOxygen = oxy; //Max oxygen for setting max oxygen with oxygen packs {item}
    this->oxygen = oxy;
}

int Player::getOxygen() const
{
    return this->oxygen;
}

int Player::getMaxOxygen() const
{
    return maxOxygen;
}

void Player::setOxygen(int newOxygen)
{
    if(newOxygen > maxOxygen)
    {
        oxygen = maxOxygen;
    }
    else
    {
        oxygen = newOxygen;
    }
}

void Player::checkCurrentStatus()
{
    if(this->getHealth() <= 0 || this->getOxygen() <= 0)
    {
        this->setCharDead(true);;
    }
}

void Player::useItem()
{
    //THIS FUNCTION WILL NEED TO BE REMOVED FROM THE PLAYER CLASS ONCE WE FIGURE OUT A BETTER WAY TO TACKLE THIS PROBLEM!!!

    int indexOfItem;

    //ask the user for input, only if there is an item in the player's inventory.
    if(!this->inventory->isEmpty())
    {
        int inventorySize = inventory->getSize();

        cout << "\nWhich item do you want to use?" << endl;
        inventory->listItems();
        cout << "Type any negative number to cancel using an item." << endl;

        cin >> indexOfItem;

        //throw this error if the user enters something illigal.
        if(!cin)
        {
            throw invalid_input("That is not a valid item.");
        }

        //if the user enters the index of an invalid item, tell them!
        if((indexOfItem > inventorySize || indexOfItem == 0))
        {
            cout << "That is not a valid item." << endl;
            return;
        }
    }
    else
    {
        cout << "You have no items to use." << endl;
        return;
    }

    if(indexOfItem <= -1)
    {
        return;
    }

    //get the item type that the specified index
    ItemType itemTypeToUse = inventory->useItem(indexOfItem - 1);

    if(itemTypeToUse == healthPack) //restore the player's health
    {
        setHealth(getMaxHealth());
        cout << "Health restored." << endl;
    }
    else if(itemTypeToUse == oxygenPack) //restore the player's oxygen
    {
        oxygen = maxOxygen;
        cout << "Oxygen restored." << endl;
    }
}
