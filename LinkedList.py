# Implementing linked lists and related methods


class Node:
    """
    Defines a simple node that can be an element of varipus different data structures.
    In this current implementation, we only track the Head node and link to the next element
    (i.e., this node type can be used for singly linked lists)
    """
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    """
    Singly linked list class with relevant methods for adding and removing elements
    """
    def __init__(self):
        """
        Initiates HEAD node
        """
        self.head = None

    def is_empty(self):
        """
        Simple check whether the list is empty
        :return: bool (True if empty)
        """
        return self.head is None

    def is_circular(self):
        """
        Determine whether there are any loops in the list
        :return: bool for existence of loop
        """
        if self.is_empty():
            return False
        runner1, runner2 = self.head, self.head
        while runner2 is not None and runner2.next is not None:
            if runner1 == runner1.next.next:
                return True
            runner1 = runner1.next
            runner2 = runner2.next.next
            if runner1 == runner2:
                return True
        return False

    def get_tail_node(self):
        """
        Gets last node in the list. Useful if creating new methods.
        :return: last node in the list (of class Node)
        """
        tail_node = self.head
        while tail_node.next is not None:
            tail_node = tail_node.next
        return tail_node

    def traverse(self, to_print=False):
        """
        Traverses the list, returns length and optionally prints list values.
        :param to_print: optional parameter - whether to print list values or not
        :return: length of list (int)
        """
        length = 0
        node = self.head
        while node is not None:
            length += 1
            if to_print:
                print(node.value)
            node = node.next
        print('Number of nodes: {}'.format(length))
        return length

    def search(self, value):
        """
        Search for, and return the position of the first node with parameter value.
        :param value: value to look for in nodes in list
        :return: position of first node with parameter value (int)
        """
        node = self.head
        counter = 0
        while node is not None:
            counter += 1
            if node.value == value:
                print('Node found! Node #: {} | Node value: {}'.format(counter, node.value))
                return node
            node = node.next
        return counter

    def prepend(self, value):
        """
        Insert a node with parameter value at the beginning of the list.
        :param value: value to be given to prepended node
        :return: None (linked list object is modified)
        """
        if self.is_empty():
            self.head = Node(value)
        else:
            node = self.head
            self.head = Node(value)
            self.head.next = node

    def append(self, value):
        """
        Add a node with parameter value at the end of the list.
        :param value: value to be given to appended node
        :return: None (linked list object is modified)
        """
        if self.is_empty():
            self.head = Node(value)
        else:
            tail_node = self.head
            while tail_node.next is not None:
                tail_node = tail_node.next
            tail_node.next = Node(value)

    def pop(self):
        """
        Remove head node from list and return its value
        :return: value of removed head node
        """
        if self.is_empty():
            return None
        else:
            node = self.head
            self.head = self.head.next
            return node.value

    def remove(self, value):
        """
        Removes node with first occurrence of value
        :param value: value to be searched for
        :return: None (linked list is modified)
        """
        if self.head.value == value:
            self.head = self.head.next
        else:
            node = self.head
            while node.next is not None:
                if node.next.value == value:
                    node.next = node.next.next
                    break
                node = node.next

    def insert(self, value, pos):
        """
        Inserts value at given position in the list. If given position is larger than the length of the list,\
        it appends value to the end of the list.
        :param value: value to be inserted
        :param pos: position to be inserted into (with zero-based indexing)
        :return: None (linked list object is modified)
        """
        if pos + 1 > self.size():
            self.append(value)
        elif pos == 0:
            self.prepend(value)
        else:
            counter = 1
            node = self.head
            subseq = self.head.next
            while counter < pos:
                node = node.next
                subseq = subseq.next
                counter += 1
            node.next = Node(value)
            node.next.next = subseq

    def size(self):
        """
        Return the length of the list (just a wrapper for self.traverse())
        :return: length of list (int)
        """
        return self.traverse()

    def to_list(self):
        out = []
        node = self.head
        while node is not None:
            out.append(node.value)
            node = node.next
        return out

    def reverse(self):
        """
        Reverses order of nodes in list
        :return: reversed list (of class LinkedList)
        """
        revd = LinkedList()
        for value in self:
            temp = revd.head
            revd.head = Node(value)
            revd.head.next = temp
        return revd

    def __iter__(self):
        node = self.head
        while node is not None:
            yield node.value
            node = node.next

    def __repr__(self):
        return str([val for val in self])


#%%
# TESTS

lst = LinkedList()
lst.prepend("333")
lst.prepend(3)
lst.prepend(5)
lst.traverse(to_print=True)

#%%
lst.append(8)
lst.traverse(to_print=True)

#%%
temp = lst.pop()
print('Popped item: {}'.format(temp))
lst.traverse(to_print=True)

#%%
node = lst.search(8)
node.value

#%%
lst.traverse(to_print=True)
lst.remove(8)
lst.traverse(to_print=True)

#%%
lst.size()

#%%
lst.insert(10, 1)
lst.traverse(to_print=True)

#%%
lst = LinkedList()
lst.append(3)
lst.append(33)
lst.append(4)
lst.append(44)
revd = lst.reverse()
revd.traverse(to_print=True)
