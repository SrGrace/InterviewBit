/*

https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/



Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

    NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 

*/



vector<int> Solution::lszero(vector<int> &A) 
{
    int sum = 0;
    map<int, int> mp;
    vector<int> v;
    
    mp.insert({0, -1});
    
    int st = -1, ed = -1, max_l = INT_MIN;
    
    for(auto i=0; i<A.size(); i++)
    {
        sum += A[i];
        
        if(mp.find(sum) != mp.end())
        {
            if(max_l < i - mp[sum])
            {
                st = mp[sum] + 1;
                ed = i;
                max_l = i - mp[sum];
            }
        }
        else
            mp.insert({sum, i});
    }
    
    if(st >=0 && ed >= 0)
    {
        for(auto i=st; i<=ed; i++)
            v.push_back(A[i]);
    }
    
    return v;
    
}



