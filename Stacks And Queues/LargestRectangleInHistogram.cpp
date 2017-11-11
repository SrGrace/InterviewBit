/*

https://www.interviewbit.com/problems/largest-rectangle-in-histogram/


Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest 
rectangle in the histogram.

For example,
Given height = [2,1,5,6,2,3],
return 10.

*/


# method 1


int Solution::largestRectangleArea(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int res = 0;
    A.push_back(0);
    
    vector<int> idx;
    
    for(auto i=0; i<A.size(); i++)
    {
        while(idx.size() > 0 && A[idx.back()] >= A[i])
        {
            int h = A[idx.back()];
            idx.pop_back();
            
            int j;
            if(idx.size() > 0)
                j = idx.back();
            else 
                j = -1;
                
            if(h*(i-j-1) > res)
                res = h*(i-j-1);
        }
        idx.push_back(i);
    }
    
    return res;
    
}

# method 2


int Solution::largestRectangleArea(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int res = 0;
    A.push_back(0);
    
    stack<int> st;
    
    for(auto i=0; i<A.size(); i++)
    {
        if(st.empty() || A[i] >= A[st.top()])
            st.push(i);
        else
        {
            int j = st.top();
            st.pop();
            res = max(res, A[j]*(st.empty() ? i : i - st.top() - 1));
            i--;
        }
    }
    
    return res;
    
}




