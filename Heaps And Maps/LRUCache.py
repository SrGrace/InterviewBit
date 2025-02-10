"""
https://www.interviewbit.com/problems/lru-cache/

Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

NOTE: If you are using any global variables, make sure to clear them in the constructor.

Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 
         
"""

# python 2.7
class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        from collections import OrderedDict
        
        class MyOrderedDict(OrderedDict): # wrapper just for python 2.7 
            def move_to_end(self, key, last=True): 
                if key not in self:
                    raise KeyError("Key not found: %r" % (key,))
                self[key] = self.pop(key)  # Move to end (or use popitem for other logic)
        
        self.cache = MyOrderedDict() # OrderedDict()
        self.capacity = capacity

    # @return an integer
    def get(self, key):
        if key in self.cache:
            self.cache.move_to_end(key) # mark key as recently used
            return self.cache[key]
        return -1

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        if key in self.cache:
            self.cache.move_to_end(key) # mark key as recently used
        self.cache[key] = value # insert/update
        
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False) # invalidate the least recently used key


# python > 3.2
class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        from collections import OrderedDict
        
        self.cache = OrderedDict()
        self.capacity = capacity

    # @return an integer
    def get(self, key): # O(n)
        if key in self.cache:
            self.cache.move_to_end(key) # mark key as recently used
            return self.cache[key]
        return -1 

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value): # O(n)
        if key in self.cache:
            self.cache.move_to_end(key) # mark key as recently used
        self.cache[key] = value # insert/update
        
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False) # invalidate the least recently used key


"""
Optimal Approach: HashMap + Doubly Linked List # O(1), O(1)
We use:

         HashMap (Dictionary):
                  To map keys to their corresponding nodes in the linked list for O(1) access.
                  
         Doubly Linked List:
                  To maintain the order of use, with the most recently used items at the front and least recently used items at the back.

Operations

1) get(key): # O(1)

         If the key exists in the cache:
                  Move the node corresponding to the key to the front of the doubly linked list (marking it as most recently used).
                  Return its value.
         If the key does not exist, return -1.
         
2) set(key, value): # O(1)

         If the key already exists:
                  Update the value.
                  Move the node to the front of the doubly linked list.
         If the key does not exist:
                  If the cache is full (i.e., exceeds capacity), remove the least recently used item (from the end of the doubly linked list).
                  Insert the new key-value pair at the front of the doubly linked list.

"""



