# Implementing a Queue based on a linked list structure


#%%
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


#%%
class QueueLL:
    def __init__(self):
        self.head = None
        self.tail = None
        self.num_elements = 0

    def is_empty(self):
        return self.num_elements == 0

    def size(self):
        return self.num_elements

    def enqueue(self, value):
        if self.is_empty():
            self.head = Node(value)
            self.tail = self.head
        else:
            self.tail.next = Node(value)
            self.tail = self.tail.next
        self.num_elements += 1

    def dequeue(self):
        if self.is_empty():
            return None
        else:
            out = self.head.value
            self.head = self.head.next
            self.num_elements -= 1
            return out

    def __iter__(self):
        node = self.head
        while node is not None:
            yield node.value
            node = node.next

    def __repr__(self):
        return str([v for v in self])


#%%
# TESTS

# Setup
q = QueueLL()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)

# Test size
print ("Pass" if (q.size() == 3) else "Fail")

# Test dequeue
print("Pass" if (q.dequeue() == 1) else "Fail")

# Test enqueue
q.enqueue(4)
print("Pass" if (q.dequeue() == 2) else "Fail")
print("Pass" if (q.dequeue() == 3) else "Fail")
print("Pass" if (q.dequeue() == 4) else "Fail")
q.enqueue(5)
print("Pass" if (q.size() == 1) else "Fail")