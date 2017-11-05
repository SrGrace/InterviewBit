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



int find_rot_cnt(const vector<int> &A)
{
    int l = 0, r = A.size()-1;
    
    while(l  <= r)
    {
        if(A[l] <= A[r]) return l;  // case 1: if the whole array is completly sorted already, i.e no rotation
        
        int mid = l + (r - l)/2;
        
        int nxt = (mid + 1)%A.size(), prev = (mid + A.size() - 1)%A.size();
        
        if(A[mid] <= A[nxt] && A[mid] <= A[prev])   // case 2:  11 12 15 '2' 3 4 5 :   15 > 2 < 3 
            return mid;
            
        else if(A[mid] <= A[r]) 
            r= mid - 1;
            
        else if(A[mid] >= A[l])
            l = mid + 1;
    }
    return -1;
}

int Solution::findMin(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return A[find_rot_cnt(A)];
    
}



