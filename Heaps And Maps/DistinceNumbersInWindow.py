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
        
        for i in range(B):
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
        
        return result # O(len(A)), O(B)
        
        
