#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <fstream>

const int MAX_ITEMS = 5;

enum RelationType {
    LESS,
    GREATER,
    EQUAL
};

class ItemType {
    public:
        ItemType();
        explicit ItemType(int);
        RelationType ComparedTo(ItemType&) const;
        void Print(std::ofstream&) const;
    private:
        int value;
};

#endif // ITEMTYPE_H
