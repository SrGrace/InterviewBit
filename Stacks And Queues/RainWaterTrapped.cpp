/*

https://www.interviewbit.com/problems/rain-water-trapped/


Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/


# 1st method (using Stack)


int Solution::trap(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    stack<int> st;
    int vol = 0;
    
    for(auto i=0; i<A.size(); i++)
    {
        while(!st.empty() && A[i] > A[st.top()])
        {
            int j = st.top();
            st.pop();
            if(st.empty())
                break;
            int d = i - st.top() - 1;
            int bounded_height = min(A[i], A[st.top()]) - A[j];
            vol += d*bounded_height;
        }
        st.push(i);
    }
    return vol;
    
}


# 2nd method (two pointer)


int Solution::trap(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    int l = 0, r = A.size()-1;
    int vol = 0, l_max = 0, r_max = 0;
    
    while(l < r)
    {
        if(A[l] < A[r])
        {
            if(A[l] >= l_max)
                l_max = A[l];
            else
                vol += (l_max - A[l]);
                
            ++l;
        }
        else
        {
            if(A[r] >= r_max)
                r_max = A[r];
            else
                vol += (r_max - A[r]);
                
            --r;
        }
    }
    return vol;
    
}



