#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

class QueueFull {};

class QueueEmpty {};

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
