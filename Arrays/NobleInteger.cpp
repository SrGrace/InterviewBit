/*

https://www.interviewbit.com/problems/noble-integer/


Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array 
equals to p
If such an integer is found return 1 else return -1.

*/



int Solution::solve(vector<int> &A) 
{
    int n = A.size();
    
    /*
    int p = 0, cnt = 0;
    
    for(auto it : A)
    {
        if(it > p) cnt++;
        if(cnt != p) 
        {
            cnt = 0;
            p = it;
        }
    }
    
    for(auto it : A)
    {
        if(it > p) cnt++;
    }
    
    if(cnt == p) return 1;
    else return -1;
    */
    
    
    std::sort(A.begin(), A.end());
    
    for(auto i=0; i<n-1; i++)
    {
        if(A[i] == A[i+1]) 
            continue;
        
        if(A[i] == n-i-1)
            return 1;
    }
    
    if(A[n-1] == 0)
        return 1;
    return -1;
}



