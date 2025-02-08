"""
https://www.interviewbit.com/problems/magician-and-chocolates/

Problem Description
 
 

Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.

Find the maximum number of chocolates that kid can eat in A units of time.

NOTE: 

floor() function returns the largest integer less than or equal to a given number.
Return your answer modulo 10^9+7


Problem Constraints
1 <= A <= 105
1 <= |B| <= 105
1 <= Bi <= INT_MAX


Input Format
First argument is an integer A.

Second argument is an integer array B of size N.



Output Format
Return an integer denoting the maximum number of chocolates that kid can eat in A units of time.



Example Input
Input 1:

 A = 3
 B = [6, 5]
Input 2:

 A = 5
 b = [2, 4, 6, 8, 10]


Example Output
Output 1:

 14
Output 2:

 33


Example Explanation
Explanation 1:

 At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates. 
 At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates. 
 At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate. 
 so, total number of chocolates eaten are 6 + 5 + 3 = 14
"""

class Solution:
    # @param A : integer
    # @param B : list of integers
    # @return an integer
    def nchoc(self, A, B):
        import heapq
	    
        max_heap = [-b for b in B]
        heapq.heapify(max_heap) # O(n)
        
        total_chocolates = 0
        for _ in range(A): # O(A)
            maxx = -heapq.heappop(max_heap) # log(n)
            total_chocolates += maxx
            
            magic = maxx//2
             
            heapq.heappush(max_heap, -magic) # log(n)
        
        return total_chocolates%1000000007 # final: O(n + Alogn)


