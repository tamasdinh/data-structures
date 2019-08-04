// In the linked implementation of the Stack ADT, the top of the stack is interpreted as the first element in the
// linked list; this way we can make Push(), Pop() and Top() O(1) operations (we don't have to traverse the list
// to get to the top element).

#include "LinkedStack.h"

struct NodeType {
    ItemType data;
    NodeType* next = nullptr;
};

LinkedStack::LinkedStack(): topPtr(nullptr) {}

LinkedStack::~LinkedStack() {
    // Traversing the list by setting topPtr to its .next member, we are deallocating the memory reserved for each node
    NodeType* tempPtr;
    while (topPtr != nullptr) {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

bool LinkedStack::isEmpty() const {
    return (topPtr == nullptr);
}

bool LinkedStack::isFull() const {
    // In a linked implementation, we assume we can go up to the total of the allocable memory. As such, the isFull()
        // check consists of checking whether we can add an additional node to the data structure or not.
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    }
    // The try-catch block makes sure that the program doesn't run into a runtime error - std::bad_alloc exception is
        // caught and handled
    catch (std::bad_alloc memException) {
        return true;
    }
}

// If the stack is not empty, a new node is created on the free store and topPtr is made to point to the new node
void LinkedStack::Push(ItemType newItem) {
    if (isFull())
        throw StackFull();
    else {
        NodeType* location = new NodeType;
        location->data = newItem;
        topPtr = location;
    }
}

// Pop() removes the top element in the list (does not return it)
void LinkedStack::Pop() {
    if (isEmpty())
        throw StackEmpty();
    else {
        NodeType* tempPtr = topPtr; // topPtr memory address is stored in tempPtr
        topPtr = topPtr->next;      // topPtr is incremented to the next node
        delete tempPtr;             // original top element is deallocated from memory
    }
}

// Top() returns the data member in the top element in the stack, without removing the top element
ItemType LinkedStack::Top() {
    if (isEmpty())
        throw StackEmpty();
    else
        return topPtr->data;
}