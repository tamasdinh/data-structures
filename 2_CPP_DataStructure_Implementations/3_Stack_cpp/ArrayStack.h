#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "../0_Auxiliary/ItemType.h"
// ItemType.h must be provided by the user of this class.

class StackFull {};
// Class for StackFull exceptions

class StackEmpty {};
// Class for StackEmpty exceptions

class ArrayStack {
    public:
        ArrayStack();   // default constructor; default size is 500
        ArrayStack(int maxItems);   // overloaded constructor: user can input maximum size of the stack
        ~ArrayStack();      // destructor
        bool isEmpty() const;
        bool isFull() const;
        void Push(ItemType newItem);
        void Pop();     // in this implementation, Pop() removes the top element and does not return it
        ItemType Top() const;   // Top() has the role of returning the top element, without removing it from the Stack
    private:
        int maxStack;   // data member for maximum size of the stack
        int top;    // index to the top element in the array
        ItemType* items;  // array of user-defined data type (the stack)
};

#endif // ARRAYSTACK_H
