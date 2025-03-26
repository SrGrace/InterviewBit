/*

https://www.interviewbit.com/problems/count-element-occurence/


Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.

*/




int bin_search(const vector<int> &A, int B, bool flgfst)
{
    int start = 0, end = A.size()-1;
    int pos = -1;
    
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if (A[mid] == B) 
        {
            pos = mid;
            if (flgfst)          
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if (B < A[mid])
            end = mid - 1;
        else 
            start = mid + 1;
    }
    
    return pos;  // O(logn)
    
}


int Solution::findCount(const vector<int> &A, int B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int fstidx = bin_search(A, B, true);
    
    if(fstidx == -1)
        return 0;

    int lstidx = bin_search(A, B, false);
    
    return lstidx - fstidx + 1;  // O(logn), O(1)
    
}



