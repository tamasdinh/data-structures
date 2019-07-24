#include <iostream>
#include "1_Unsorted-List_Linked_CPP/UnsortedList.h"

int main() {

    using namespace std;

    // Unsorted List linked implementation tests

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



};

