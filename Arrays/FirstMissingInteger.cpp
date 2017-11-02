/*

https://www.interviewbit.com/problems/first-missing-integer/


Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

*/



# 1st method

int Solution::firstMissingPositive(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    int n=A.size();
    
    for(int i = 0; i < n; ++i)
    {   
        if (A[i] > 0 && A[i] <= n) {
            int idx = A[i] - 1;
            
            if (A[idx] != A[i]) 
            {
                swap(A[idx], A[i]);
                i--;
            }
        }
        
    }
    
    for(int i = 0; i < n; ++i) 
    {   
        if(A[i] != i + 1)
            return i + 1;
    }
    
    return n + 1;
    
}
 
 

# 2nd method

int Solution::firstMissingPositive(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    
    std::sort(A.begin(), A.end());
    
    int missing = 1;
    
    for (auto const& a : A)
    {
        if (a < 1)
            continue;
            
        else if (a == missing)
        {
            ++missing;
            continue;
        }
        else
            break;
    }
    
    return missing;
    
}





