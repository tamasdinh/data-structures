# Implementing a Queue based on a stack structure


#%%
class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)

    def push(self, value):
        self.items.append(value)

    def pop(self):
        if self.is_empty():
            return None
        else:
            return self.items.pop()


class QueueS:
    def __init__(self):
        self.instore = Stack()
        self.outstore = Stack()

    def size(self):
        return self.outstore.size() + self.instore.size()

    def enqueue(self, value):
        """
        Adding item to the end of the queue
        :param value: value to be added at end of queue
        :return: None - instore member is modified
        """
        self.instore.push(value)

    def dequeue(self):
        """
        Dequeuing elements. Here we use 2 stacks so that we can reverse the order of items\
        in the second one for dequeuing.
        :return: dequeued item
        """
        if not self.outstore.items:
            while self.instore.items:
                self.outstore.push(self.instore.pop())
        return self.outstore.pop()


#%%
# TESTS

# Setup
q = QueueS()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)

# Test size
print("Pass" if (q.size() == 3) else "Fail")

# Test dequeue
print("Pass" if (q.dequeue() == 1) else "Fail")

# Test enqueue
q.enqueue(4)
print("Pass" if (q.dequeue() == 2) else "Fail")
print("Pass" if (q.dequeue() == 3) else "Fail")
print("Pass" if (q.dequeue() == 4) else "Fail")
q.enqueue(5)
print("Pass" if (q.size() == 1) else "Fail")
