/*

https://www.interviewbit.com/problems/distinct-numbers-in-window/


You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence 
Ai, Ai+1 ,…, Ai+k-1.

Note:

    If K > N, return empty array.

For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].

*/




vector<int> Solution::dNums(vector<int> &A, int B) 
{
    map<int, int> mp;
    vector<int> v;
    
    int cnt = 0;
    
    for(auto i=0; i<B; i++)
    {
        if(mp[A[i]] == 0)
            cnt++;
        mp[A[i]]++;
    }
    v.push_back(cnt);
    
    for(auto i=B; i<A.size(); i++)
    {
        // Remove first element of previous window
        // If there was only one occurrence, then reduce distinct count.
        if(mp[A[i-B]] == 1)
            cnt--;
            
        // reduce count of the removed element
        mp[A[i-B]]--;
        
        // Add new element of current window
        // If this element appears first time,
        // increment distinct element count
        if(mp[A[i]] == 0)
            cnt++;
        mp[A[i]]++;
        
        v.push_back(cnt);
    }
    
    return v;
}


