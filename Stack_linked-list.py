# Implementing a stack based on a linked list structure


#%%
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


#%%
class StackLL:
    def __init__(self):
        self.head = None
        self.num_elements = 0

    def is_empty(self):
        return self.head is None

    def size(self):
        return self.num_elements

    def push(self, value):
        if self.is_empty():
            self.head = Node(value)
        self.head.next = self.head
        self.head = Node(value)
        self.num_elements += 1

    def pop(self):
        if self.is_empty():
            return None
        ppd = self.head.value
        self.head = self.head.next
        self.num_elements -= 1
        return ppd


#%%
# TESTS
# Setup
stack = StackLL()
stack.push(10)
stack.push(20)
stack.push(30)
stack.push(40)
stack.push(50)

# Test size
print("Pass" if (stack.size() == 5) else "Fail")

# Test pop
print("Pass" if (stack.pop() == 50) else "Fail")

# Test push
stack.push(60)
print("Pass" if (stack.pop() == 60) else "Fail")
print("Pass" if (stack.pop() == 40) else "Fail")
print("Pass" if (stack.pop() == 30) else "Fail")
stack.push(50)
print("Pass" if (stack.size() == 3) else "Fail")
