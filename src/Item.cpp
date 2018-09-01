#include "Item.h"

using namespace std;

Item::Item()
{

}

string Item::printItemName() const
{
    return itemName;
}

ItemType Item::getItemType() const
{
    return type;
}
