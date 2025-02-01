"""
https://www.interviewbit.com/problems/merge-k-sorted-lists/

Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20

"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param A : list of linked list
    # @return the head node in the linked list
    def mergeKLists(self, A):
        import heapq
        
        # Create a min heap
        min_heap = []
        
        # Initialize the heap with the first node from each list
        for i in range(len(A)):
            if A[i]:
                heapq.heappush(min_heap, (A[i].val, i, A[i]))  # (value, index, node)
        
        # Dummy node to build the result list
        dummy = ListNode(0)
        current = dummy
        
        # Extract the minimum element and move the pointer to the next node in the list
        while min_heap:
            val, idx, node = heapq.heappop(min_heap)
            current.next = node
            current = current.next
            if node.next:
                heapq.heappush(min_heap, (node.next.val, idx, node.next))
        
        return dummy.next # O(nlogk), n= total nodes, k = no. of lists
        
  
