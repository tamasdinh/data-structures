#include "ArrayStack.h"

ArrayStack::ArrayStack(): maxStack(500), top(-1), items(new ItemType[maxStack]) {}
// initializing top to -1 provides a good way to check emptiness and avoids clashing with array indices

ArrayStack::ArrayStack(int maxItems): maxStack(maxItems), top(-1), items(new ItemType[maxStack]) {}

ArrayStack::~ArrayStack() {
    // Takes care of the only item constructed on the free store, items.
    delete [] items;
}

bool ArrayStack::isEmpty() const {
    return (top == -1);
}

bool ArrayStack::isFull() const {
    return (top == maxStack - 1);
}

void ArrayStack::Push(ItemType newItem) {
    if (isFull())
        throw StackFull();
    top++;
    items[top] = newItem;
}

void ArrayStack::Pop() {
    if (isEmpty())
        throw StackEmpty();
    top--;
}

ItemType ArrayStack::Top() const {
    if (isEmpty())
        throw StackEmpty();
    return items[top];
}
