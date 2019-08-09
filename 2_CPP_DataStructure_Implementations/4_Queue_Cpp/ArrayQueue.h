#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "../0_Auxiliary/QueueFull.h"
#include "../0_Auxiliary/QueueEmpty.h"


template <typename T>
class ArrayQueue {
    public:
        ArrayQueue();
        ArrayQueue(int);
        ArrayQueue(ArrayQueue&);
        ~ArrayQueue();
        void MakeEmpty();
        bool IsEmpty() const;
        bool IsFull() const;
        void Enqueue(T);
        T Dequeue(T&);

    private:
        T* items_;
        int max_queue_;
        int front_;
        int rear_;
};


#endif // ARRAYQUEUE_H
