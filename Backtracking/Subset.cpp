/*

https://www.interviewbit.com/problems/subset/


Given a set of distinct integers, S, return all possible subsets.

    Note:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        Also, the subsets should be sorted in ascending ( lexicographic ) order.
        The list is not necessarily sorted.

Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

*/



void backtrack(vector<int> &A, int st, vector<vector<int> > &v, vector<int> &v1)
{
    v.push_back(v1);
    for(auto i=st; i<A.size(); i++)
    {
        v1.push_back(A[i]);
        backtrack(A, i+1, v, v1);
        v1.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    sort(A.begin(), A.end());
    
    vector<vector<int> > v;
    vector<int> v1;
    
    backtrack(A, 0, v, v1);
    
    return v;
}


