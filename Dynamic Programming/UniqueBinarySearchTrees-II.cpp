/*

https://www.interviewbit.com/problems/unique-binary-search-trees-ii/


Given A, how many structurally unique BST’s (binary search trees) that store values 1...A?

Example :

Given A = 3, there are a total of 5 unique BST’s.


   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/



# Soln Approach

Lets consider the number [1, n]
We have n options of choosing the root.
If we choose the number j as the root, j - 1 numbers fall in the left subtree, n - j numbers fall in the right subtree. 
We already know how many ways there are to forming j - 1 trees using j - 1 numbers and n -j numbers.
So we add number(j - 1) * number(n - j) to our solution.




int Solution::numTrees(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int dp[A+2];
    memset(dp, 0, sizeof(dp));
    
    dp[0] = 1, dp[1] = 1;
    
    for(auto i=2; i<=A; i++)
    {
        for(auto j=1; j<=i; j++)
        {
            dp[i] += (dp[j-1] * dp[i-j]);
        }
    }
    
    return dp[A];
    
}



