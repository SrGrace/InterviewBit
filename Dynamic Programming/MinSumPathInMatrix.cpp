/*

https://www.interviewbit.com/problems/min-sum-path-in-matrix/


Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time. 

Example :

Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1

*/



int Solution::minPathSum(vector<vector<int> > &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int r = A.size(), c = A[0].size();
    
    int dp[r+2][c+2];
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = A[0][0];
    
    for(int i=1; i<r; i++)
        dp[i][0] = dp[i-1][0] + A[i][0];
    
    for(int i=1; i<c; i++)
        dp[0][i] = dp[0][i-1] + A[0][i];
        
    for(int i=1; i<r; i++)
    {
        for(int j=1; j<c; j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + A[i][j];
        }
    }
    
    return dp[r-1][c-1];
}


