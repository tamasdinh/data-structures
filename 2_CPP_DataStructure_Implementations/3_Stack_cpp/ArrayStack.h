#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

class StackFull {};
// Class for StackFull exceptions

class StackEmpty {};
// Class for StackEmpty exceptions

template <typename T>
class ArrayStack {
    public:
        ArrayStack();   // default constructor; default size is 500
        ArrayStack(ArrayStack&);  // copy constructor
        ArrayStack(int maxItems);   // overloaded constructor: user can input maximum size of the stack
        ~ArrayStack();      // destructor
        bool isEmpty() const;
        bool isFull() const;
        void Push(T newItem);
        void Pop();     // in this implementation, Pop() removes the top element and does not return it
        T Top() const;   // Top() has the role of returning the top element, without removing it from the Stack
    private:
        int maxStack;   // data member for maximum size of the stack
        int top;    // index to the top element in the array
        T* items;  // array of user-defined data type (the stack)
};

#endif // ARRAYSTACK_H
