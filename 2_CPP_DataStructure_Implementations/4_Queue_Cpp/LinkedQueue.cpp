#include "LinkedQueue.h"
#include "../0_Auxiliary/ItemType.h"

struct NodeType {
    ItemType data;
    NodeType* next = nullptr;
};

// This Queue implementation is based on a circular linked list structure so that memory space can be saved by only
// storing a pointer rear_ to the rear element. The front element is accessed via rear_->next.
LinkedQueue::LinkedQueue(): rear_(nullptr) {};

LinkedQueue::~LinkedQueue() {
    MakeEmpty();
}

void LinkedQueue::MakeEmpty() {
    if (!IsEmpty()) {
        NodeType* tempPointer = nullptr;
        while (rear_->next != rear_) {
            tempPointer = rear_->next;
            rear_->next = rear_->next->next;
            delete tempPointer;
        }
        if (rear_ != nullptr)
            delete rear_;
        rear_ = nullptr;
    }
}

bool LinkedQueue::IsFull() const {
    try {
        NodeType* location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception) {
        return true;
    }
}

bool LinkedQueue::IsEmpty() const {
    return (rear_ == nullptr);
}

void LinkedQueue::Enqueue(ItemType newItem) {
    if (IsFull())
        throw QueueFull();
    else {
        NodeType* newNode = new NodeType;
        newNode->data = newItem;
        if (rear_ == nullptr) {
            rear_ = newNode;
            rear_->next = newNode;
        }
        else {
            newNode->next = rear_->next;
            rear_->next = newNode;
            rear_ = newNode;
        }
    }
}

ItemType LinkedQueue::Dequeue() {
    if (IsEmpty())
        throw QueueEmpty();
    else {
        ItemType item;
        NodeType* tempPointer = rear_->next;
        item = rear_->next->data;
        if (rear_->next == rear_)
            rear_ = nullptr;
        else
            rear_->next = rear_->next->next;
        delete tempPointer;
        return item;
    }
}