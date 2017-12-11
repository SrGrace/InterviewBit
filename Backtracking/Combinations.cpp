/*

https://www.interviewbit.com/problems/combinations/



Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

    Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
    Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

    Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
    Example : itertools.combinations in python.
    If you do, we will disqualify your submission retroactively and give you penalty points. 

*/



void comb(int n, int k, int st, vector<vector<int> > &v, vector<int> v1)
{
    if(k == 0)
    {
        v.push_back(v1);
        return;
    }
    for(auto i=st; i<=n; i++)
    {
        v1.push_back(i);
        comb(n, k-1, i+1, v, v1);
        v1.pop_back();
    }
}

vector<vector<int> > Solution::combine(int n, int k) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > v;
    vector<int> v1;
    
    comb(n, k, 1, v, v1);
    sort(v.begin(), v.end());
    
    return v;
}


