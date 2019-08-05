#include "ArrayCountedQueue.h"

// we use ArrayQueue's constructor but also initialize the length_ data member
// (all other data members, including front_, rear_ and items_, are initialized by the base class constructor)
ArrayCountedQueue::ArrayCountedQueue(int max): ArrayQueue(max), length_(0) {}

int ArrayCountedQueue::GetLength() const {
    return length_;
}

void ArrayCountedQueue::Enqueue(ItemType newItem) {
    // we can use Enqueue() from ArrayQueue but have to include it in a try-catch block to handle exceptions
    try {
        ArrayQueue::Enqueue(newItem);
        length_++;
    }
    catch (QueueFull) {
        throw QueueFull();
    }
}

void ArrayCountedQueue::Dequeue(ItemType &item) {
    // we can use Dequeue() from ArrayQueue but have to include it in a try-catch block to handle exceptions
    try {
        ArrayQueue::Dequeue(item);
        length_--;
    }
    catch (QueueEmpty) {
        throw QueueEmpty();
    }
}