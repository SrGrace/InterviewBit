"""
https://www.interviewbit.com/problems/profit-maximisation/ 

Problem Description
 
Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= 1000000



Input Format
First argument is the array A.

Second argument is integer B.


Output Format
Return one integer, the answer to the problem.


Example Input
Input 1:

A = [2, 3]
B = 3
Input 2:

A = [1, 4]
B = 2


Example Output
Output 1:

7
Output 2:

7


Example Explanation
Explanation 1:

 First you serve the seat with number = 3. Then with 2 and then with 2. hence answer = 3 + 2 + 2 = 7.
Explanation 2:

 You give both tickets from the row with 4 seats. 4 + 3 = 7.
"""


class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        import heapq
        max_heap = [-a for a in A]
        heapq.heapify(max_heap)
        
        profit = 0
        for _ in range(B):
            # get max seat
            max_seat = -heapq.heappop(max_heap)
            
            # add to profit
            profit += max_seat
            
            # decrease max seat
            if max_seat - 1 > 0:
                heapq.heappush(max_heap, -(max_seat-1))
        
        return profit
         
