"""
https://www.interviewbit.com/problems/meeting-rooms/

Problem Description
 
Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
 
Find the minimum number of conference rooms required so that all meetings can be done.

Note :- If a meeting ends at time t, another meeting starting at time t can use the same conference room


Problem Constraints
1 <= N <= 105
0 <= A[i][0] < A[i][1] <= 2 * 109

Input Format
The only argument given is the matrix A.

Output Format
Return the minimum number of conference rooms required so that all meetings can be done.

Example Input & Output
Input 1:
 A = [      [0, 30]
            [5, 10]
            [15, 20]
     ]
Output 1:
 2

Input 2:
 A =  [     [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13]
      ]
Output 2:
 4

Example Explanation
Explanation 1:

 Meeting one can be done in conference room 1 form 0 - 30.
 Meeting two can be done in conference room 2 form 5 - 10.
 Meeting three can be done in conference room 2 form 15 - 20 as it is free in this interval.
 
Explanation 2:

 Meeting one can be done in conference room 1 from 1 - 18.
 Meeting five can be done in conference room 2 from 2 - 11.
 Meeting four can be done in conference room 3 from 4 - 15.
 Meeting six can be done in conference room 4 from 5 - 13.
 Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
 Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.

"""


import heapq

class Solution:
    # @param A : list of list of integers
    # @return an integer
    def solve(self, intervals):
        if not intervals:
            return 0

        # Sort the intervals by start time
        intervals.sort(key=lambda x: x[0])

        # Min-heap to track the earliest ending meeting
        heap = []
        heapq.heappush(heap, intervals[0][1])  # Push the end time of the first meeting

        # Iterate through the remaining intervals
        for i in range(1, len(intervals)):
            start, end = intervals[i]

            # If the current meeting can reuse the room with the earliest ending time
            if heap and start >= heap[0]:
                heapq.heappop(heap)  # Free up the room

            # Assign the current meeting to a room (push its end time into the heap)
            heapq.heappush(heap, end)

        # The size of the heap is the minimum number of rooms required
        return len(heap)  # O(nlogn) O(n)
            
