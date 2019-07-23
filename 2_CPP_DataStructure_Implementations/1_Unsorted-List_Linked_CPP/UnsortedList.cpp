#include "UnsortedList.h"

struct NodeType {
    ItemType data;
    NodeType* next = nullptr;
};

UnsortedListLinked::UnsortedListLinked() {
    // Initializing list length to 0 and current headNode's pointer to NULL
    length = 0;
    headNode = nullptr;
    currentPos = nullptr;
}

UnsortedListLinked::~UnsortedListLinked() {
    // list object does not need a destructor as it goes out of scope at the end of its initialization block, but
    // related free store objects need to be deallocated from memory
    NodeType* tempPointer;
    while (headNode != nullptr) {
        // iterating through list nodes and deallocating their memory space
        tempPointer = headNode;
        headNode = headNode->next;
        delete tempPointer;
    }
}

void UnsortedListLinked::MakeEmpty() {
    // We effectively iterate through the list nodes and freeing up the memory allocated to them one-by-one.
    NodeType* tempPointer;
    while(headNode != nullptr) {
        tempPointer = headNode;
        headNode = headNode->next;
        delete tempPointer;
    }
    length = 0;     // simply updating the "length" variable to 0 as list has been emptied
}

bool UnsortedListLinked::isFull() const {
    // Returns false if there is room in the free store to initialize another headNode
    NodeType* location;
    try {
        // after initializing a pointer to a NodeType object, we are trying to initialize a new headNode on the free store.
            // if it's successful, the function returns false.
        location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc& badAllocException) {
        // if there is no more space in the free store, C++ will throw a std::bad_alloc exception.
            // we are catching the std::bad_alloc exception to avoid program termination and return true in the function.
        return true;
    }
}

int UnsortedListLinked::getLength() const {
    // Simply return the length of the list (stored in the "length" private data member)
    return length;
}

ItemType UnsortedListLinked::getItem(ItemType item, bool &found) const {
    // We traverse the list items and compare the data member of each node to the item sought
    NodeType* location = headNode;  // initialize the temporary node pointer variable to the headNode
    found = false;
    bool continueSearch = (location != nullptr);
    while (continueSearch && !found) {
       // while the boolean var continueSearch is true AND the item has not been found, the item sought is compared to
            // items in the list successively
        switch (item.ComparedTo(location->data)) {
            case LESS :
            case GREATER:   location = location->next;
                            continueSearch = (location != nullptr);
                            break;
            case EQUAL:     found = true;
                            item = location->data;
                            break;
        }
    }
    return item;
}

void UnsortedListLinked::putItem(ItemType item) {
    // the list being unsorted, we can add a new element simply at the beginning
    NodeType* newNode = new NodeType();     // creating new node for item
    newNode->data = item;                   // inserting item as data member to new node
    newNode->next = headNode;               // connecting new node via next member to existing headNode
    headNode = newNode;                     // assigning new node as headNode
    length++;                               // incrementing length attribute of list
}

void UnsortedListLinked::deleteItem(ItemType item) {
    // We iterate through the list elements with the temporary variables location and tempLocation
    NodeType* location = headNode;      // initializing location to head node in the list
    NodeType* tempLocation;

    if (item.ComparedTo(headNode->data) == EQUAL) {
        // Special case if headNode contains the item to be deleted
        tempLocation = location;    // head node memory pointer saved to tempLocation for memory deallocation
        headNode = headNode->next;  // new head node is the next node in the list
    }
    else {
        while(item.ComparedTo(location->next->data) != EQUAL) {
            // traverse through list nodes as long as the next node is not the one to be deleted
            location = location->next;
        }
        // if the next node in the list is the one to be deleted, store its pointer into tempLocation for memory deallocation
        tempLocation = location->next;
        location->next = location->next->next; // set current node's (last one before deleted) next pointer to deleted + 1. node in the list
    }
    delete tempLocation;    // execute memory deallocation for node deleted from list
    length--;   // decrement list length attribute
}

void UnsortedListLinked::resetList() {
    // Simply setting currentPos to NULL (aligns with getNextItem(), which progresses currentPos to headNode if currentPos == NULL)
    currentPos = nullptr;
}

ItemType UnsortedListLinked::getNextItem() {
    // Simply returning the data member in the NodeType struct that the currentPos node's "next" data member points to
    if (currentPos == nullptr)
        currentPos = headNode;
    else
        currentPos = currentPos->next;
    return currentPos->data;
}

