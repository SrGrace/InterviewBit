"""

https://www.interviewbit.com/problems/merge-k-sorted-arrays/

Problem Description

You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

You need to merge them into a single array and return it.



Problem Constraints
1 <= K, N <= 103

0 <= A[i][j] <= 108

A[i][j] <= A[i][j+1]



Input Format
First and only argument is an 2D integer matrix A.



Output Format
Return a integer array denoting the merged array you get after merging all the arrays in A.



Example Input
Input 1:

 A = [  [1, 2, 3]
        [2, 4, 6]
        [0, 9, 10]
     ]


Example Output
Output 1:

 [0, 1, 2, 2, 3, 4, 6, 9, 10]


Example Explanation
Explanation 1:

 You need to merge [1, 2, 3] , [2, 4, 6] and [0, 9, 10]  into a single array
 so the merged array will look like [0, 1, 2, 2, 3, 4, 6, 9, 10]

"""


class Solution:
    # @param A : list of list of integers
    # @return a list of integers
    def solve(self, A):
        import heapq 
        
        # The heap will store tuples of the form (element_value, array_index, element_index)
        min_heap = []
        result = []

        # Step 1: Initialize the heap with the first element of each array
        K = len(A)
        N = len(A[0])
        
        for i in range(K):
            if A[i]:  # if the array is not empty
                heapq.heappush(min_heap, (A[i][0], i, 0))  # Push (value, array_index, element_index)

        # Step 2: Extract elements from the heap and add them to the result
        while min_heap:
            val, array_idx, ele_idx = heapq.heappop(min_heap)
            result.append(val)  # Add the smallest element to result
            
            # If there is another element in the same array, push it to the heap
            if ele_idx + 1 < N:
                next_val = A[array_idx][ele_idx + 1]
                heapq.heappush(min_heap, (next_val, array_idx, ele_idx + 1))
        
        return result # O(n*klogk), O(n*k)
        
