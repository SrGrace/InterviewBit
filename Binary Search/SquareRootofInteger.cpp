/*

https://www.interviewbit.com/problems/square-root-of-integer/



Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY

*/





int Solution::sqrt(int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A == 0 || A == 1)
        return A;
        
    int l = 1, r = A, res;
    
    while(l <= r)
    {
        int mid = l + (r - l)/2;
        if(mid == A/mid)
            return mid;
            
        if(mid < A/mid)
        {
            l = mid+1;
            res = mid;   // since it is floor(sqrt(x))
        }
        
        else
            r = mid-1;
         
    }
    
    return res; // O(logn), O(1)
}





