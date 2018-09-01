#include "Inventory.h"
#include "Item.h"
#include "ShipPart.h"
#include <iostream>

using namespace std;


Inventory::Inventory(Weapon* startWeapon)
{
    hasPhonyShipPart = false;

    gun = startWeapon;

    size = 0;
    numOfShipParts = 0;
    //initialize all entries in the inventory to nullptr
    for(int i = 0; i < 10; i++)
    {
        itemArray[i] = nullptr;
    }
}

Inventory::~Inventory()
{
    delete gun;
    for(int i = 0; i < size; i++)
    {
        delete itemArray[i];
    }
}


void Inventory::addItem(Item * itemToAdd){

    //if the inventory is full, they cannot add the item to it
    if(size == 10)
    {
        cout << "You cannot pick up " << itemToAdd->printItemName() << "." << endl;
        return;
    }

    //if the item is a ship part, then add it separatly.
    if(itemToAdd->getItemType() == shipPart)
    {
        ShipPart* shipPart = static_cast<ShipPart*>(itemToAdd);
        if(shipPart->isPartPhony())
        {
            hasPhonyShipPart = true;
        }

        numOfShipParts++;
        delete itemToAdd;
    }
    else
    {
        itemArray[size] = itemToAdd;
        size++;
    }
}

ItemType Inventory::useItem(int itemNum)
{
    Item *temp;

    ItemType type = itemArray[itemNum]->useItem();
    size--;

    delete itemArray[itemNum];

    //shift all entries in the inventory over one
    if(size > 0){
        for(int i = itemNum; i < size; i++){
            temp = itemArray[i + 1];
            itemArray[i] = temp;
        }
    }
    return type;
}


void Inventory::listItems(){

    if(size == 0)
    {
        cout << "You have nothing in your inventory." << endl;
    }
    else{
        cout << "You have collected " << numOfShipParts << " ship part";
        (numOfShipParts == 1) ? (cout << "." << endl) : (cout << "s." << endl);
        cout << endl;
        for(int i = 0; i < size; i++){
            cout << (i + 1) << ". " << itemArray[i]->printItemName() << endl;

        }
    }
}

Weapon Inventory::getWeapon() const
{
    return *gun;
}

int Inventory::getSize() const
{
    return size;
}

int Inventory::getNumOfShipParts() const
{
    return numOfShipParts;
}

ItemType Inventory::getItemTypeAtIndex(int index) const
{
    return itemArray[index]->getItemType();
}

bool Inventory::isEmpty() const
{
    return size == 0;
}

bool Inventory::getHasPhonyShipPart() const
{
    return hasPhonyShipPart;
}

void Inventory::setHasPhonyShipPart(bool newValue)
{
    this->hasPhonyShipPart = newValue;
}
