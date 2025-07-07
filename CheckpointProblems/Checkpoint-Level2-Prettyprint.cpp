/*

https://www.interviewbit.com/problems/prettyprint/


Print concentric rectangular pattern in a 2d matrix.
Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.
Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 

Example 2:

Input: A = 3.
Output:

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 

The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

You will be given A as an argument to the function you need to implement, and you need to return a 2D array.

*/





vector<vector<int> > Solution::prettyPrint(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = 2*A-1;
    int lim = n, tmp = 0;
    
    vector<vector<int> > v(n, vector<int> (n));
    
    while(A > 0)
    {
        for(auto i=tmp; i<lim; i++)
        {
            for(auto j=tmp; j<lim; j++)
            {
                v[i][j] = A;
            }
        }
        
        A--;
        lim--;
        tmp++;
    }
    
    return v; // O(n^2), O(n)
    
}





