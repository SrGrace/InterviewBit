
// http://practice.geeksforgeeks.org/problems/next-larger-element/0

# Next Larger Element


vector<int> Solution::nextLarger(vector<int> &A) 
{
    vector<int> v(A.size());
    stack<int> st;
    
    for(auto i=0; i<A.size(); i++)
    {
        while(!st.empty() && A[i] >= A[st.top()])
        {
            v[st.top()] = A[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        v[st.top()] = -1;
        st.pop();
    }
    
    return v;
}



