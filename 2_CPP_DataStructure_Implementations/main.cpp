#include <iostream>
#include "1_Unsorted-List_Linked_CPP/UnsortedList.h"
#include "3_Stack_cpp/ArrayStack.h"
#include "3_Stack_cpp/ArrayStack.cpp"
#include "4_Queue_Cpp/LinkedQueue.h"
#include "4_Queue_Cpp/ArrayQueue.h"
#include "4_Queue_Cpp/ArrayQueue.cpp"
#include "5_ListPlus/DoublyLinkedList.h"


// Exercise 18

// Option A
// The simplest solution here is passing-by-value the data structure to be examined, which of course requires that
// the implementation of the data structure has a copy constructor that effectively creates a deep copy of the data
// structure, which includes creating a copy of any members that are only referenced with their memory address inside
// the data structure.
bool IdenticalA(ArrayStack<int> Stack1, ArrayStack<int> Stack2) {
    while (!Stack1.isEmpty() || !Stack2.isEmpty()) {
        if (Stack1.Top() != Stack2.Top())
            return false;
        Stack1.Pop();
        Stack2.Pop();
    }
    return true;
}

// Option B
// (I wasn't sure Option A above satisfies the exercise requirement that we should not assume any knowledge of the data
// structure's implementation, so I added an Option B below - although in my interpretation, including a copy constructor
// is standard if one has members in the data structure initialized on the free store.)

// The second option involves transferring the elements in the ADTs into two proxy Stack ADTs (this is necessary due to the
// LIFO nature of the Stack ADT), and checking for similarity when Popping the elements. This way similarity can be
// determined, and subsequently, elements can be filled back to the original structures to ensure that they are returned
// from the function unchanged.
// In this case, no copy constructor has to be implemented in the ADT implementation, and the data structure to be
// examined can be passed-by-reference to the function.
bool IdenticalB(ArrayStack<int> &Stack1, ArrayStack<int> &Stack2) {
    ArrayStack<int>* proxyStack1 = new ArrayStack<int>;
    ArrayStack<int>* proxyStack2 = new ArrayStack<int>;
    bool isIdentical = true;
    while (!Stack1.isEmpty() || !Stack2.isEmpty()) {
        try {
            if (Stack1.Top() != Stack2.Top()) {
                isIdentical = false;
                break;
            }
        }
        catch (StackEmpty) {
            isIdentical = false;
            break;
        }
        proxyStack1->Push(Stack1.Top());
        proxyStack2->Push(Stack2.Top());
        Stack1.Pop();
        Stack2.Pop();
    }
    while (!proxyStack1->isEmpty() && !proxyStack2->isEmpty()) {
        Stack1.Push(proxyStack1->Top());
        Stack2.Push(proxyStack2->Top());
        proxyStack1->Pop();
        proxyStack2->Pop();
    }
    return isIdentical;
}

void IdenticalTestReport1(std::string version, bool& isIdentical) {
    std::cout << "\t\t" << version << " - Are the two stacks identical? - " << (isIdentical ? "True" : "False")
              << std::endl;
}
void IdenticalTestReport2(ArrayStack<int>& Stack1, ArrayStack<int>& Stack2) {
    std::cout << "\t\tIs Stack1 full? - " << (Stack1.isFull() ? "True" : "False") << std::endl;
    std::cout << "\t\tIs Stack2 full? - " << (Stack2.isFull() ? "True" : "False") << std::endl;

    std::cout << "\t\tStack1 elements: ";
    while (!Stack1.isEmpty()) {
        std::cout << Stack1.Top() << " ";
        Stack1.Pop();
    }
    std::cout << std::endl;

    std::cout << "\t\tStack2 elements: ";
    while (!Stack2.isEmpty()) {
        std::cout << Stack2.Top() << " ";
        Stack2.Pop();
    }
    std::cout << std::endl;
}


// Exercise 37

// Option A
// The simplest solution here is also passing-by-value the data structure to be examined, which of course requires that
// the implementation of the data structure has a copy constructor that effectively creates a deep copy of the data
// structure, which includes creating a copy of any members that are only referenced with their memory address.
int GetLengthA(ArrayQueue<int> arrayQueue) {
    int length = 0;
    int item = 1;
    while (!arrayQueue.IsEmpty()) {
        arrayQueue.Dequeue(item);
        length++;
    }
    return length;
}

// Option B
// The second option here also involves dequeuing the elements in the ADT into a proxy Queue ADT, and incrementing the
// counter every step. This way the length of the structure can be determined, and subsequently, elements can be filled
// back to the original structure to ensure that it is returned from the function unchanged.
// In this case, no copy constructor has to be implemented in the ADT implementation, and the data structure to be
// examined can be passed-by-reference to the function.
int GetLengthB(ArrayQueue<int> &arrayQueue) {
    ArrayQueue<int>* tempQueue = new ArrayQueue<int>;
    int length = 0;
    int item = 1;
    while (!arrayQueue.IsEmpty()) {
        tempQueue->Enqueue(arrayQueue.Dequeue(item));
        length++;
    }
    while (!tempQueue->IsEmpty())
        arrayQueue.Enqueue(tempQueue->Dequeue(item));
    delete tempQueue;
    return length;
}

int main() {

    using namespace std;

    // Unsorted List linked implementation tests
    std::cout << "\nUnsorted List linked implementation tests --" << std::endl;

        // Constructor
        UnsortedListLinked linkedList;
        cout << "List length (empty): " << linkedList.getLength() << endl;

        // putItem()
        for (int i = 1; i <= 5; i++)
            linkedList.putItem(ItemType(i));
        cout << "List length (5 elements): " << linkedList.getLength() << endl;
        cout << "List elements: ";
        for (int i = 0; i < linkedList.getLength(); i++) {
            linkedList.getNextItem().Print();
            if (i == linkedList.getLength() - 1)
                cout << endl;
        }

        // getItem()
        cout << "Element 3: ";
        linkedList.getItem(ItemType(3)).Print();
        cout << endl;

        // isFull()
        cout << "Is list full? -- " << linkedList.isFull() << endl;

        // deleteItem()
        linkedList.deleteItem(ItemType(3));
        linkedList.resetList();
        cout << "List elements: ";
        for (int i = 0; i < linkedList.getLength(); i++) {
            linkedList.getNextItem().Print();
        }
        cout << endl;


    // Circular linked queue tests
    std::cout << "\nCircular linked queue tests --" << std::endl;
        // Creating queue
        std::cout << "\nCreating queue --" << std::endl;
        LinkedQueue queue;
        std::cout << "Is queue empty? " << queue.IsEmpty() << std::endl;

        // Enqueuing elements
        std::cout << "\nEnqueuing elements --" << std::endl;
        std::cout << "Adding 1..." << std::endl;
        queue.Enqueue(ItemType(1));
        std::cout << "Adding 2..." << std::endl;
        queue.Enqueue(ItemType(2));
        std::cout << "Adding 3..." << std::endl;
        queue.Enqueue(ItemType(3));
        std::cout << "Is queue empty? " << queue.IsEmpty() << std::endl;
        std::cout << "Is queue full? " << queue.IsFull() << std::endl;

        // Dequeuing elements
        std::cout << "\nDequeuing elements --" << std::endl;
        std::cout << "Removing 1 element (should be 1)..." << std::endl;
        std::cout << "Removed element: ";
        queue.Dequeue().Print();
        std::cout << std::endl;
        std::cout << "Removing 1 element (should be 2)..." << std::endl;
        std::cout << "Removed element: ";
        queue.Dequeue().Print();
        std::cout << std::endl;
        std::cout << "Removing 1 element (should be 3)..." << std::endl;
        std::cout << "Removed element: ";
        queue.Dequeue().Print();
        std::cout << std::endl;

        std::cout << "Is queue empty? " << queue.IsEmpty() << std::endl;
        std::cout << "Is queue full? " << queue.IsFull() << std::endl;

        // MakeEmpty()
        std::cout << "\nMakeEmpty() --" << std::endl;
        std::cout << "\tEnqueuing elements --" << std::endl;
        std::cout << "Adding 1..." << std::endl;
        queue.Enqueue(ItemType(1));
        std::cout << "Adding 2..." << std::endl;
        queue.Enqueue(ItemType(2));
        std::cout << "Adding 3..." << std::endl;
        queue.Enqueue(ItemType(3));
        std::cout << "Is queue empty? " << queue.IsEmpty() << std::endl;
        std::cout << "Running MakeEmpty()..." << std::endl;
        queue.MakeEmpty();
        std::cout << "Is queue empty? " << queue.IsEmpty() << std::endl;


    // Exercise 18

    // Testing Identical()
    std::cout << "\nIdentical() tests ----------" << std::endl;

        // Stacks are same with 10 elements each
        std::cout << "\tTest case 1: identical stacks with 10 elements --" << std::endl;
    {
        ArrayStack<int> Stack1(10);
        ArrayStack<int> Stack2(10);
        bool isIdentical;

        for (int i = 1; i <= 10; i++) {
            Stack1.Push(i);
        }
        for (int i = 1; i <= 10; i++) {
            Stack2.Push(i);
        }
        isIdentical = IdenticalA(Stack1, Stack2);
        IdenticalTestReport1("Version A", isIdentical);
        isIdentical = IdenticalB(Stack1, Stack2);
        IdenticalTestReport1("Version B", isIdentical);

        IdenticalTestReport2(Stack1, Stack2);
    }

        // Stacks are different with 10 elements each
        std::cout << "\n\tTest case 2: different stacks with 10 elements each --" << std::endl;
    {
        ArrayStack<int> Stack1(10);
        ArrayStack<int> Stack2(10);
        bool isIdentical;
        for (int i = 1; i <= 10; i++) {
            Stack1.Push(i);
        }
        for (int i = 1; i <= 10; i++) {
            if (i == 3)
                Stack2.Push(4);
            else
                Stack2.Push(i);
        }
        isIdentical = IdenticalA(Stack1, Stack2);
        IdenticalTestReport1("Version A", isIdentical);
        isIdentical = IdenticalB(Stack1, Stack2);
        IdenticalTestReport1("Version B", isIdentical);

        IdenticalTestReport2(Stack1, Stack2);
    }

        // Stacks are same but with different element counts
        std::cout << "\n\tTest case 3: same stacks with different element counts --" << std::endl;
    {
        ArrayStack<int> Stack1(10);
        ArrayStack<int> Stack2(9);
        bool isIdentical;
        for (int i = 1; i <= 10; i++) {
            Stack1.Push(i);
        }
        for (int i = 2; i <= 10; i++) {
            Stack2.Push(i);
        }
        isIdentical = IdenticalA(Stack1, Stack2);
        IdenticalTestReport1("Version A", isIdentical);
        isIdentical = IdenticalB(Stack1, Stack2);
        IdenticalTestReport1("Version B", isIdentical);

        IdenticalTestReport2(Stack1, Stack2);
    }

    // Stacks are same but with duplication
    std::cout << "\n\tTest case 4: same stacks with duplication --" << std::endl;
    {
        ArrayStack<int> Stack1(10);
        ArrayStack<int> Stack2(11);
        bool isIdentical;
        for (int i = 1; i <= 10; i++) {
            Stack1.Push(i);
        }
        for (int i = 1; i <= 11; i++) {
            if (i == 11)
                Stack2.Push(10);
            else
                Stack2.Push(i);
        }
        isIdentical = IdenticalA(Stack1, Stack2);
        IdenticalTestReport1("Version A", isIdentical);
        isIdentical = IdenticalB(Stack1, Stack2);
        IdenticalTestReport1("Version B", isIdentical);

        IdenticalTestReport2(Stack1, Stack2);
    }


    // Exercise 37

    // Testing GetLength()
    std::cout << "\n\nGetLength() tests ----------" << std::endl;

        // Queue with 10 elements
        std::cout << "\n\tTest case 1: queue with 10 elements --" << std::endl;
    {
        ArrayQueue<int> Queue(10);
        int length;
        int item;

        for (int i = 1; i <= 10; i++) {
            Queue.Enqueue(i);
        }

        length = GetLengthA(Queue);
        std::cout << "\t\tVersion A" << " - The length of the queue is: " << length << std::endl;
        length = GetLengthB(Queue);
        std::cout << "\t\tVersion B" << " - The length of the queue is: " << length << std::endl;
        std::cout << "\t\tIs Queue full? - " << (Queue.IsFull() ? "True" : "False") << std::endl;

        std::cout << "\t\tQueue elements: ";
        while (!Queue.IsEmpty()) {
            std::cout << Queue.Dequeue(item) << " ";
        }
        std::cout << std::endl;
    }

    // Empty queue
    std::cout << "\n\tTest case 2: empty queue --" << std::endl;
    {
        ArrayQueue<int> Queue(10);
        int length;
        int item;

        length = GetLengthA(Queue);
        std::cout << "\t\tVersion A" << " - The length of the queue is: " << length << std::endl;
        length = GetLengthB(Queue);
        std::cout << "\t\tVersion B" << " - The length of the queue is: " << length << std::endl;
        std::cout << "\t\tIs Queue full? - " << (Queue.IsFull() ? "True" : "False") << std::endl;

        std::cout << "\t\tQueue elements: ";
        while (!Queue.IsEmpty()) {
            std::cout << Queue.Dequeue(item) << " ";
        }
        std::cout << std::endl;
    }

// DoublyLinkedList tests

        DoublyLinkedList textList;

        std::cout << (textList.IsEmpty()? "List is empty" : "List is not empty") << std::endl;
        textList.GoToTop();
        std::cout << "Inserting element..." << std::endl;
        textList.InsertLine(LineType("Hello"));
        std::cout << (textList.IsEmpty()? "List is empty" : "List is not empty") << std::endl;
        std::cout << std::endl;

        textList.GoToBottom();
        textList.InsertLine(LineType("Hello2"));
        textList.InsertLine(LineType("Hello3"));
        textList.InsertLine(LineType("Hello4"));
        textList.GoToTop();
        std::cout << "List elements:" << std::endl;
        while (textList.getCurrentLine()->getNext() != nullptr) {
            textList.getCurrentLine()->print();
            textList.incrementCurrentLine();
        }
}