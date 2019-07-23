#ifndef UNSORTED_LIST_H
#define UNSORTED_LIST_H

#include "ItemType.h"

struct NodeType;    // forward declaration for headNode in the linked list; implementation in .cpp file

class UnsortedListLinked {
    public:
        UnsortedListLinked();   // default constructor
        ~UnsortedListLinked();  // default destructor - in order to ensure freeing of memory allocated on the free store for the nodes
        void MakeEmpty();       // clearing data from list items
        bool isFull() const;    // determines whether the list has reached its maximum size - in the current
                                    // linked implementation, this means that there are no memory left in the free store
        int getLength() const;  // returns length of list (number of elements in list)
        ItemType getItem(ItemType item, bool& found) const;    // returns item from list if exists
        void putItem(ItemType item);    // insert item in list
        void deleteItem(ItemType item); // delete item from list
        void resetList();       // initializes current position in the list for any iterator
        ItemType getNextItem(); // returns next item in the list (for iteration purposes)

    private:
        NodeType* headNode;
        int length;
        NodeType* currentPos;
};

#endif // UNSORTED_LIST_H
