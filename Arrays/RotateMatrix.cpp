/*

https://www.interviewbit.com/problems/rotate-matrix/


You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]

Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]

*/



void transpose(vector<vector<int> > &A)
{
    for(auto i=0; i<A.size(); i++)
    {
        for(auto j=i; j<A[0].size(); j++)
        {
            swap(A[i][j], A[j][i]);
        }
    }
}

void reverseRows(vector<vector<int> > &A)
{
    for (int i=0; i<A.size(); i++)
        for (int j=0,  k=A.size()-1; j<k; j++,k--)
            swap(A[i][j], A[i][k]);
}

void Solution::rotate(vector<vector<int> > &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    transpose(A);
    
    reverseRows(A);
}




