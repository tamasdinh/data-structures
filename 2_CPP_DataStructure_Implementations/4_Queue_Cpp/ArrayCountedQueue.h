#ifndef ARRAYCOUNTEDQUEUE_H
#define ARRAYCOUNTEDQUEUE_H

#include "../0_Auxiliary/ItemType.h"
#include "ArrayQueue.h"

// ArrayCountedQueue inherits all attributes from ArrayQueue, overriding the constructor, Enqueue() and Dequeue()
//methods, and adds a length_ member with a corresponding GetLength() accessor function so that queue length can be monitored.
class ArrayCountedQueue : public ArrayQueue {
    public:
        ArrayCountedQueue(int max);
        void Enqueue(ItemType newItem);
        void Dequeue(ItemType& item);
        int GetLength() const;
    private:
        int length_;
};

#endif //INC_2_CPP_DATASTRUCTURE_IMPLEMENTATIONS_ARRAYCOUNTEDQUEUE_H
