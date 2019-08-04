#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "../0_Auxiliary/ItemType.h"

struct NodeType;

class StackEmpty {};

class StackFull{};

class LinkedStack {
    public:
        LinkedStack();
        ~LinkedStack();
        void Push(ItemType);
        void Pop();
        ItemType Top();
        bool isEmpty() const;
        bool isFull() const;
    private:
        NodeType* topPtr;
};


#endif // LINKEDSTACK_H
