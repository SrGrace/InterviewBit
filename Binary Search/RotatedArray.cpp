/*

https://www.interviewbit.com/problems/rotated-array/



Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.

        NOTE 1: Also think about the case when there are duplicates. Does your current solution work? How does the time 
        complexity change?*

PROBLEM APPROACH:

Note: If you know the number of times the array is rotated, then this problem becomes trivial. If the number of rotation is x, 
then minimum element is A[x].

*/


# With or Without duplicates


class Solution {
public:
    int pivot(vector<int> &A)
    {
        int n = A.size();
        int l = 0, r = n-1;
        
        while(l < r)
        {
            int mid = l + (r-l)/2;
            
            if(A[mid] < A[r])
                r = mid;
            else if(A[mid] > A[r])
                l = mid+1;
            else 
                r--;  // eliminate duplicates
        }
        return l;
    }
    int findMin(vector<int>& A) 
    {
        return A[pivot(A)];
    }
};


