#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "../0_Auxiliary/ItemType.h"

class QueueFull {};

class QueueEmpty {};

class ArrayQueue {
    public:
        ArrayQueue();
        ArrayQueue(int);
        ~ArrayQueue();
        void MakeEmpty();
        bool IsEmpty() const;
        bool IsFull() const;
        void Enqueue(ItemType);
        void Dequeue(ItemType&);

    private:
        ItemType* items_;
        int max_queue_;
        int front_;
        int rear_;
};


#endif // ARRAYQUEUE_H
