"""
https://www.interviewbit.com/problems/maximum-sum-combinations/

Problem Description
 
 

Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.



Problem Constraints
1 <= N <= 105

1 <= A[i] <= 105

1 <= C <= N



Input Format
First argument is an one-dimensional integer array A of size N.

Second argument is an one-dimensional integer array B of size N.

Third argument is an integer C.



Output Format
Return a one-dimensional integer array of size C denoting the top C maximum sum combinations.

NOTE:

The returned array must be sorted in non-increasing order.



Example Input
Input 1:

 A = [3, 2]
 B = [1, 4]
 C = 2
Input 2:

 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4


Example Output
Output 1:

 [7, 6]
Output 1:

 [10, 9, 9, 8]


Example Explanation
Explanation 1:

 7     (A : 3) + (B : 4)
 6     (A : 2) + (B : 4)
Explanation 2:

 10   (A : 4) + (B : 6)
 9   (A : 4) + (B : 5)
 9   (A : 3) + (B : 6)
 8   (A : 3) + (B : 5)
 
"""


class Solution:
    # @param A : list of integers
    # @param B : list of integers
    # @param C : integer
    # @return a list of integers
    def solve(self, A, B, C):   
        A.sort(reverse=True) # O(nlogn)
        B.sort(reverse=True) # O(nlogn)
        
        import heapq
        max_heap = []
        visited = set()
        
        # push largest sum into heap
        heapq.heappush(max_heap, (-(A[0]+B[0]), 0, 0))
        visited.add((0, 0))
        
        result = list()
        for _ in range(C):
            if not max_heap:
                break
            
            # get largest sum and indices
            curr_sum, i, j = heapq.heappop(max_heap) # O(clogc)
            result.append(-curr_sum)
            
            # explore next possible sums
            # (i+1, j) if possible
            if i+1 < len(A) and (i+1, j) not in visited:
                heapq.heappush(max_heap, (-(A[i+1]+B[j]), i+1, j)) # O(clogc)
                visited.add((i+1, j))
            
            # (i, j+1) if possible
            if j+1 < len(B) and (i, j+1) not in visited:
                heapq.heappush(max_heap, (-(A[i]+B[j+1]), i, j+1)) # O(clogc)
                visited.add((i, j+1))
        
        return result # final: O(nlogn + clogc)
            
            
