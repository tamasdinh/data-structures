#include "ArrayQueue.h"

template <typename T>
ArrayQueue<T>::ArrayQueue() {
    max_queue_ = 501;         // default size of queue is 500; +1 slot is for the reserved slot referenced by front_ one slot before the actual front element
    front_ = max_queue_ - 1;  // front_ is set to one slot before the actual front element
    rear_ = max_queue_ - 1;   // rear_ is set initially to the same position as front_, so that emptiness can be easily checked
    items_ = new T[max_queue_];
}

template <typename T>
ArrayQueue<T>::ArrayQueue(ArrayQueue &arrayQueue) {
    max_queue_ = arrayQueue.max_queue_;
    front_ = arrayQueue.front_;
    rear_ = arrayQueue.rear_;
    items_ = new T[max_queue_];
    for (int i = 0; i < max_queue_; i++) {
        items_[i] = arrayQueue.items_[i];
    }
}

template <typename T>
ArrayQueue<T>::ArrayQueue(int max_size) {
    max_queue_ = max_size + 1;
    front_ = max_queue_ - 1;
    rear_ = max_queue_ - 1;
    items_ = new T[max_queue_];
}

template <typename T>
ArrayQueue<T>::~ArrayQueue<T>() {
    delete [] items_;
}

template <typename T>
void ArrayQueue<T>::MakeEmpty() {
    front_ = max_queue_ -1;
    rear_ = max_queue_ - 1;
}

template <typename T>
bool ArrayQueue<T>::IsEmpty() const {
    return (front_ == rear_);
}

template <typename T>
bool ArrayQueue<T>::IsFull() const {
    return ((rear_ + 1) % max_queue_ == front_);  // modulo operation makes rear_ wrap around the array if needed
}

template <typename T>
void ArrayQueue<T>::Enqueue(T newItem) {
    if (IsFull())
        throw QueueFull();
    else {
        rear_ = (rear_ + 1) % max_queue_;
        items_[rear_] = newItem;
    }
}

template <typename T>
T ArrayQueue<T>::Dequeue(T &item) {
    if (IsEmpty())
        throw QueueEmpty();
    else {
        front_ = (front_ + 1) % max_queue_;
        return item = items_[front_];
    }
}