# Implementing queues based on an array structure


#%%
class QueueArray:
    def __init__(self, initial_size=10):
        self.arr = [0 for _ in range(initial_size)]
        self.next_index = 0
        self.front_index = -1
        self.queue_size = 0

    def is_empty(self):
        return self.queue_size == 0

    def size(self):
        return self.queue_size

    def front(self):
        if self.is_empty():
            return None
        return self.arr[self.front_index]

    def enqueue(self, value):
        if self.queue_size == len(self.arr):
            self._handle_queue_capacity_full()

        self.arr[self.next_index] = value
        self.next_index += 1
        if self.front_index == -1:
            self.front_index = 0
        self.queue_size += 1

    def dequeue(self):
        if self.is_empty():
            return None
        out = self.arr[self.front_index]
        self.front_index += 1
        self.queue_size -= 1
        return out

    def _handle_queue_capacity_full(self):
        old_arr = self. arr
        self.arr = [0 for _ in range(len(old_arr) * 2)]

        for i in range(len(old_arr)):
            self.arr[i] = old_arr[self.front_index + i]

        self.front_index = 0
        self.next_index = len(old_arr)


#%%
# Checking initialization
q = QueueArray()
print(q.arr)
print("Pass" if q.arr == [0, 0, 0, 0, 0, 0, 0, 0, 0, 0] else "Fail")

#%%
# Checking whole queue

# Setup
q = QueueArray()
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
