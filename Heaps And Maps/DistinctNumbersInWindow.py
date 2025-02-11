"""

https://www.interviewbit.com/problems/distinct-numbers-in-window/


You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence 
Ai, Ai+1 ,…, Ai+k-1.

Note:

    If K > N, return empty array.

For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].


"""

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of integers
    def dNums(self, A, B):
        result = list()
        
        if B > len(A):
            return result
            
        # Hash map to store frequencies
        from collections import defaultdict
        freq_map = defaultdict(int)
	    
        distinct_count = 0

	# first window
        for i in range(B): # O(B), O(B)
            if freq_map[A[i]] == 0:
                distinct_count += 1
            freq_map[A[i]] += 1
            
        result.append(distinct_count)
        
        # slide the window
        for i in range(B, len(A)):
            # remove elements going out of the window
            element_out = A[i-B]
            freq_map[element_out] -= 1
            if freq_map[element_out] == 0:
                distinct_count -= 1
                
            # add new elements coming in
            element_in = A[i]
            if freq_map[element_in] == 0:
                distinct_count += 1  
            freq_map[element_in] += 1
            
            # update result
            result.append(distinct_count)
        
        return result # O(n-B) O(n-B)
        
        
