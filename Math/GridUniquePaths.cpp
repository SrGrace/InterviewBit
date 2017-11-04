/*

https://www.interviewbit.com/problems/grid-unique-paths/


A robot is located at the top-left corner of an A x B grid.

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
              

*/



int Solution::uniquePaths(int A, int B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A > B) return uniquePaths(B, A);
    
    vector<int> p(A, 1);
    
    for(auto i=1; i<B; i++)
    {
        for(auto j=1; j<A; j++)
        {
            p[j] += p[j-1];
        }
    }
    
    return p[A-1];
}


