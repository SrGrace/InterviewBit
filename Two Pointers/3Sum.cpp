/*

# 3 Sum Closest (leetcode) https://leetcode.com/problems/3sum-closest/description/


https://www.interviewbit.com/problems/3-sum/


Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

*/



int Solution::threeSumClosest(vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int res = 0;
    if(A.size() < 3)
        return res;
        
    sort(A.begin(), A.end());
        
    res = A[0] + A[1] + A[2];
    
    for(int i=0; i<A.size()-2; i++)
    {
        int l = i+1, r = A.size() - 1;
        while(l < r)
        {
            int num = A[i] + A[l] + A[r];
            if(abs(B - num) < abs(B - res))
                res = num;
            if(num < B)
                l++;
            else 
                r--;
        }
    }
    
    return res;
}



