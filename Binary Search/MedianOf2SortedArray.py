"""

https://www.interviewbit.com/problems/median-of-array/


There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3

    NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element.
    For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 
    
"""
 

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # ensure nums1 is the smaller array for O(log(min(m,n))), O(1) solution
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        # initialization
        m, n = len(nums1), len(nums2)
        total = m+n
        half = total // 2 
        left, right = 0, m

        # binary search loop
        while(left <= right):
            i = (left+right)//2 # elements from nums1 in left half
            j = half - i # elements from nums2 in left half

            # handling boundaries (edge cases)
            nums1_left_max = float('-inf') if i == 0 else nums1[i-1]
            nums1_right_min = float('inf') if i == m else nums1[i]
            nums2_left_max = float('-inf') if j == 0 else nums2[j-1]
            nums2_right_min = float('inf') if j == n else nums2[j]

            # perfect partition check
            if nums1_left_max <= nums2_right_min and nums2_left_max <= nums1_right_min:
                # median calculation
                if total % 2 == 1:
                    return min(nums1_right_min, nums2_right_min)
                else:
                    return (max(nums1_left_max, nums2_left_max) + min(nums1_right_min, nums2_right_min))/2
            # If nums1's left is too large, reduce elements from nums1. 
            elif nums1_left_max > nums2_right_min:
                right = i - 1
            # Otherwise, increase them.
            else:
                left = i + 1

          
