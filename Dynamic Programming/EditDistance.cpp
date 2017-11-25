/*

https://www.interviewbit.com/problems/edit-distance/


Given two words A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example :
edit distance between
"Anshuman" and "Antihuman" is 2.

    Operation 1: Replace s with t.
    Operation 2: Insert i.

*/


# Solution Approach

/*

The idea is process all characters one by one staring from either from left or right sides of both strings.
Let we traverse from right corner, there are two possibilities for every pair of character being traversed.

m: Length of str1 (first string)
n: Length of str2 (second string)

    If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. 
    So we recur for lengths m-1 and n-1.
    Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last 
    character of first string, recursively compute minimum cost for all three operations and take minimum of three values.
        Insert: Recur for m and n-1
        Remove: Recur for m-1 and n
        Replace: Recur for m-1 and n-1
*/



int Solution::minDistance(string A, string B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int m = A.size(), n = B.size();
    
    int dp[m+2][n+2];
    
    for(auto i=0; i<=m; i++)
    {
        for(auto j=0; j<=n; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
                
            else
            {
                                // insert,        remove,      replace
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }
    
    return dp[m][n];
}


