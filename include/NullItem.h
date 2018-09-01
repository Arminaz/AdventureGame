#ifndef NULLITEM_H
#define NULLITEM_H

#include "Item.h"


class NullItem : public Item
{
    public:
        NullItem();
        virtual ~NullItem();

        ItemType useItem();

    protected:

    private:
};

#endif // NULLITEM_H
