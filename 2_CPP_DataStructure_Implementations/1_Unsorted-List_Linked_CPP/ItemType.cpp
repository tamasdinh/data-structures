#include "ItemType.h"

ItemType::ItemType() {
    value = 0;
}

ItemType::ItemType(int number){
    value = number;
}

RelationType ItemType::ComparedTo(ItemType& otherItem) const {
    if (value < otherItem.value)
        return LESS;
    if (value == otherItem.value)
        return EQUAL;
    if (value > otherItem.value)
        return GREATER;
}

void ItemType::Print(std::ofstream& out) const {
    // Preconditions: out has been opened
    // Post conditions: value has been sent to the stream out.
    out << value << " ";
}

