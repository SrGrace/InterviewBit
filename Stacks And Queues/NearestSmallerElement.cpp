/*

https://www.interviewbit.com/problems/nearest-smaller-element/


Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]

Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10, 8]
Return : [-1, 4, -1, 2, 2]

Example 2:

Input : A : [3, 2, 1]
Return : [-1, -1, -1]

*/


vector<int> Solution::prevSmaller(vector<int> &A) 
{
    vector<int> v(A.size());
    stack<int> st;
    
    for(auto i=0; i<A.size(); i++)
    {
        while(!st.empty() && A[i] <= A[st.top()])
        {
            //v[st.top()] = A[i];
            st.pop();
        }
        if(st.empty())
            v[i] = -1;
        else
            v[i] = A[st.top()];
            
        st.push(i);
    }
    
    return v;
}


