#ifndef ITEMTYPE_H
#define ITEMTYPE_H

//#include <fstream>      // included for file operations in ::Print() function
#include <iostream>

const int MAX_ITEMS = 5;    // defining MAX_ITEMS as a constant for holding the maximum size of the list

enum RelationType {     // defining an enum for the ComparedTo() method
    LESS,
    GREATER,
    EQUAL
};

class ItemType {
    public:
        ItemType();     // default constructor
        explicit ItemType(int);     // alternative, parameterized constructor
        RelationType ComparedTo(ItemType&) const;   // compared the value in current item to the value in another item (of ItemType)
        void Print() const;   // prints value to standard output device
    private:
        int value;      // private data member to hold the value included in the item
};

#endif // ITEMTYPE_H
