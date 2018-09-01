#include "NullItem.h"

NullItem::NullItem()
{
    type = nullItem;
}

NullItem::~NullItem()
{
    //dtor
}

ItemType NullItem::useItem()
{
    return type;
}
