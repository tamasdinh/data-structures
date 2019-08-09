#include "DoublyLinkedList.h"

/*
 * LineType class method implementations
 */

LineType::LineType(): next_(nullptr), back_(nullptr) {
    // default LineType constructor simply sets next_ and back_ to nullptr and reserves memory space for line_
    line_ = new char[80];
}

LineType::LineType(std::string line): next_(nullptr), back_(nullptr)  {
    // alternative constructor does what default constructor does + initiates line_ to include the input string as a char array
    line_ = new char[80];
    for (size_t i = 0; i < line.length(); i++)
        line_[i] = line[i];
}

LineType::LineType(const LineType &otherLineType): next_(nullptr), back_(nullptr)  {
    // copy constructor does a deep copy of another LineType object's members
    line_ = new char[80];
    for (int i = 0; i < 80; i++)
        line_[i] = otherLineType.line_[i];
}

LineType::~LineType() {
    // destructor deallocates memory for line_
    delete [] line_;
}

void LineType::setLine(std::string line) {
    // resets line_ contents to input line (for already instantiated LineType object)
    for (size_t i = 0; i < line.length(); i++)
        line_[i] = line[i];
}

LineType* LineType::getNext() {
    return this->next_;
}

void LineType::print() {
    std::cout << line_ << std::endl;
}

/*
 * DoublyLinkedList class method implementations
 */

DoublyLinkedList::DoublyLinkedList() {
    // instantiate header and trailer members to requested string contents
    LineType* header = new LineType("- - - Top of File - - -");
    LineType* trailer = new LineType("- - - Bottom of File - - -");

    // setting up doubly linked structure for header and trailer
    header->next_ = trailer;
    header->back_ = nullptr;
    trailer->next_ = nullptr;
    trailer->back_ = header;

    // setting currentLine_ to header in empty list
    currentLine_ = header;
}

DoublyLinkedList::~DoublyLinkedList() {
    // first go to the first actual line in the list
    GoToTop();
    // if the list is empty, GoToTop() took currentLine_ to point to the header node - if not, we back it up once more
    if (!IsEmpty())
        currentLine_ = currentLine_->back_;
    LineType* tempPointer;
    int counter = 0;
    // via utilization of the tempPointer, this section traverses the list and deallocates nodes one-by-one
    while (currentLine_ != nullptr) {
        tempPointer = currentLine_;
        currentLine_ = currentLine_->next_;
        delete tempPointer;
        // counter makes sure that we can account for the number of nodes deallocated
        counter += 1;
    }
    // Report on the standard output how many nodes were destructed
    std::cout << "\nDoublyLinkedList object deallocated from memory - " << counter << " list items deallocated." << std::endl;
}

bool DoublyLinkedList::IsEmpty() const {
    return (currentLine_->next_ == nullptr && currentLine_->back_->back_ == nullptr) ||
           (currentLine_->back_ == nullptr && currentLine_->next_->next_ == nullptr);
}

LineType* DoublyLinkedList::getCurrentLine() const {
    return currentLine_;
}

void DoublyLinkedList::incrementCurrentLine() {
    currentLine_ = currentLine_->next_;
}

void DoublyLinkedList::GoToTop() {
    // set currentLine_ to first line after header node
    if (currentLine_->back_ != nullptr) {
        while (currentLine_->back_->back_ != nullptr)
            currentLine_ = currentLine_->back_;
    }
    // if list is empty, back up currentLine_ to header node
    if (IsEmpty() && currentLine_->back_ != nullptr)
        currentLine_ = currentLine_->back_;
}

void DoublyLinkedList::GoToBottom() {
    // sets currentLine_ to the last node before the trailer node
    if (currentLine_->next_ != nullptr) {
        while (currentLine_->next_->next_ != nullptr)
            currentLine_ = currentLine_->next_;
    }
    // if list is empty, set currentLine_ to trailer node
    if (IsEmpty())
        currentLine_ = currentLine_->next_;
}

void DoublyLinkedList::InsertLine(LineType newLine) {
    // insert newline after currentLine_
    LineType* newline_ = new LineType(newLine);
    newline_->next_ = currentLine_->next_;
    newline_->back_ = currentLine_;
    currentLine_->next_->back_ = newline_;
    currentLine_->next_ = newline_;
    // update currentLine_ position to newLine;
    currentLine_ = newline_;
}