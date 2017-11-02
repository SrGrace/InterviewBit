/*

https://www.interviewbit.com/problems/Maximum-Absolute-Difference/

You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.

*/


int Solution::maxArr(vector<int> &A) 
{
    assert(!A.empty());
    
    int m1=INT_MIN, m2=INT_MIN, m3=INT_MIN, m4=INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        m1=max(m1, A[i]+i);
        m2=max(m2, -A[i]+i);
        m3=max(m3, A[i]-i);
        m4=max(m4, -A[i]-i);
    }
    int ans=INT_MIN;
   
    for(int i=0;i<A.size();i++)
    {
        ans=max(ans, m1 - A[i]-i);
        ans=max(ans, m2 + A[i]-i);
        ans=max(ans, m3 - A[i]+i);
        ans=max(ans, m4 + A[i]+i);
    }
    return ans;
}


