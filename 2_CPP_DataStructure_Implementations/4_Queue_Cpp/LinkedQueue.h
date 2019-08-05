#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "../0_Auxiliary/ItemType.h"
#include <iostream>

struct NodeType;

class QueueFull {};

class QueueEmpty {};

class LinkedQueue {
    public:
        LinkedQueue();
        ~LinkedQueue();
        void MakeEmpty();
        bool IsEmpty() const;
        bool IsFull() const;
        void Enqueue(ItemType newItem);
        ItemType Dequeue();
    private:
        NodeType* rear_;
};


#endif // LINKEDQUEUE_H
