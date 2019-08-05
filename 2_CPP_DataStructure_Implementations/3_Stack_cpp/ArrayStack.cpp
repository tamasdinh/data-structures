#include "ArrayStack.h"

template<typename T>
// initializing top to -1 provides a good way to check emptiness and avoids clashing with array indices
ArrayStack<T>::ArrayStack(): maxStack(500), top(-1) {
    items = new T[maxStack];
}

template <typename T>
ArrayStack<T>::ArrayStack(ArrayStack<T> &arrayStackOther): maxStack(arrayStackOther.maxStack), top(arrayStackOther.top) {
    items = new T[maxStack];
    for (int i = 0; i < arrayStackOther.top; i++) {
        items[i] = arrayStackOther.items[i];
    }
}

template<typename T>
ArrayStack<T>::ArrayStack(int maxItems): maxStack(maxItems), top(-1) {
    items = new T[maxStack];
};

template<typename T>
ArrayStack<T>::~ArrayStack() {
    // Takes care of the only item constructed on the free store, items.
    delete[] items;
}

template<typename T>
bool ArrayStack<T>::isEmpty() const {
    return (top == -1);
}

template<typename T>
bool ArrayStack<T>::isFull() const {
    return (top == maxStack - 1);
}

template<typename T>
void ArrayStack<T>::Push(T newItem) {
    if (isFull())
        throw StackFull();
    top++;
    items[top] = newItem;
}

template<typename T>
void ArrayStack<T>::Pop() {
    if (isEmpty())
        throw StackEmpty();
    top--;
}

template<typename T>
T ArrayStack<T>::Top() const {
    if (isEmpty())
        throw StackEmpty();
    return items[top];
}
