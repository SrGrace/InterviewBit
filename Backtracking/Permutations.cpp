/*

https://www.interviewbit.com/problems/permutations/



Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]

    NOTE

        No two entries in the permutation sequence should be the same.
        For the purpose of this problem, assume that all the numbers in the collection are unique.

    Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
    Example : next_permutations in C++ / itertools.permutations in python.
    If you do, we will disqualify your submission retroactively and give you penalty points. 

*/


void permutation(vector<int> &A, int st, vector<vector<int> > &v)
{
    if(st >= A.size())
    {
        v.push_back(A);
        return;
    }
    for(auto i=st; i<A.size(); i++)
    {
        swap(A[st], A[i]);
        permutation(A, st+1, v);
        swap(A[st], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > v;
    
    permutation(A, 0, v);
    
    return v;
}


