#include "ArrayQueue.h"

ArrayQueue::ArrayQueue() {
    max_queue_ = 501;         // default size of queue is 500; +1 slot is for the reserved slot referenced by front_ one slot before the actual front element
    front_ = max_queue_ - 1;  // front_ is set to one slot before the actual front element
    rear_ = max_queue_ - 1;   // rear_ is set initially to the same position as front_, so that emptiness can be easily checked
    items_ = new ItemType[max_queue_];
}

ArrayQueue::ArrayQueue(int max_size) {
    max_queue_ = max_size + 1;
    front_ = max_queue_ - 1;
    rear_ = max_queue_ - 1;
    items_ = new ItemType[max_queue_];
}

ArrayQueue::~ArrayQueue() {
    delete [] items_;
}

void ArrayQueue::MakeEmpty() {
    front_ = max_queue_ -1;
    rear_ = max_queue_ - 1;
}

bool ArrayQueue::IsEmpty() const {
    return (front_ == rear_);
}

bool ArrayQueue::IsFull() const {
    return ((rear_ + 1) % max_queue_ == front_);  // modulo operation makes rear_ wrap around the array if needed
}

void ArrayQueue::Enqueue(ItemType newItem) {
    if (IsFull())
        throw QueueFull();
    else {
        rear_ = (rear_ + 1) % max_queue_;
        items_[rear_] = newItem;
    }
}

void ArrayQueue::Dequeue(ItemType &item) {
    if (IsEmpty())
        throw QueueEmpty();
    else {
        front_ = (front_ + 1) % max_queue_;
        item = items_[front_];
    }
}