#include "ItemType.h"

ItemType::ItemType() {
    // default constructor initializes encapsulated integer private data member "value" to 0.
    value = 0;
}

ItemType::ItemType(int number){
    // alternative constructor initializes integer private data member "value" to user input number
    value = number;
}

RelationType ItemType::ComparedTo(ItemType& otherItem) const {
    // compares the value in the current ItemType to the value in another ItemType
    if (value < otherItem.value)
        return LESS;
    if (value > otherItem.value)
        return GREATER;
    else
        return EQUAL;
}

void ItemType::Print(std::ofstream& out) const {
    // prints value in current item to the standard output device

    // Preconditions: out has been opened
    // Post conditions: value has been sent to the stream out.
    out << value << " ";
}

