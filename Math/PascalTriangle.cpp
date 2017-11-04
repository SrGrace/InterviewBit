/*

https://www.interviewbit.com/problems/pascal-triangle/


Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

*/



vector<vector<int> > Solution::generate(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int>> v(A);
    
    for(auto i=0; i<A; i++)
    {
        v[i].resize(i+1);
        
        v[i][0] = v[i][i] = 1;
        
        for(auto j=0; j<i; j++)
        {
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    
    return v;
    
}




