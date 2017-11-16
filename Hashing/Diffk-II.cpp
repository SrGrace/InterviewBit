/*

https://www.interviewbit.com/problems/diffk-ii/


Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2

Output :

1

as 3 - 1 = 2

    Return 0 / 1 for this problem.

*/


int Solution::diffPossible(const vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if (A.size() < 2 || B < 0) 
        return 0;
        
    unordered_set<int> st;
    
    for(auto i = 0; i < A.size(); i++)
    {
        int Aj = A[i] - B;
        
        int Ai = A[i] + B;
        
        if (st.find(Aj) != st.end()) 
            return 1;
        if (st.find(Ai) != st.end()) 
            return 1;
            
        st.insert(A[i]);
    }
    
    return 0;
}


