#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <string>

// LineType is implemented as a class, to make instantiation with strings easier
class LineType {
    friend class DoublyLinkedList;  // due to the fact that LineType is a class, DoublyLinkedList needs to have access to its private members
    public:
        LineType(); // default constructor - not used in the examples
        explicit LineType(std::string line);    // constructor that instantiates the string contents of the line
        LineType(const LineType&);  // copy constructor (needed due to line_ being a pointer)
        ~LineType();    // destructor

        void setLine(std::string);  // can be used to change the contents of line_
        LineType* getNext();    // needed so that client code can request the next_ element
        void print();   // rint contents of LineType (the line_ member) to the standard output

    private:
        LineType* next_;    // pointer to next item
        LineType* back_;    // pointer to previous item
        char* line_;        // data (string) content of LineType object
};

class DoublyLinkedList {
    public:
        DoublyLinkedList(); // default constructor
        DoublyLinkedList(const DoublyLinkedList&);  // copy constructor - not implemented yet as it is not needed for examples
        ~DoublyLinkedList();    // destructor

        bool IsEmpty() const;   // check whether the list is empty (i.e. only header and trailer nodes present)
        LineType* getCurrentLine() const;   // get currentLine_ from client code (used for testing)
        void incrementCurrentLine();    // set currentLine_ to currentLine_->next_ from client code

        void GoToTop(); // sets currentLine_ to list item after header node (or header node if list is empty)
        void GoToBottom();  // sets currentLine_ to list item before trailer node (or trailer node if list is empty)
        void InsertLine(LineType newLine);  // insert LineType item (line) after the item pointed to by currentLine_;

    private:
        LineType* currentLine_; // points to the line currently "edited"
};

#endif // DOUBLYLINKEDLIST_H
