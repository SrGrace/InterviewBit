/*

https://www.interviewbit.com/problems/matrix-search/




Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

        Integers in each row are sorted from left to right.
        The first integer of each row is greater than or equal to the last integer of the previous row.

Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem

*/


# 1st method


bool bin_search(vector<int> &A, int l, int r, int B)
{
    while(l <= r)
    {
        int mid = l + (r - l)/2;
        
        if(A[mid] == B) 
            return 1;
            
        else if(A[mid] < B)
            l = mid + 1;
            
        else 
            r = mid - 1;
    }
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int col = A[0].size();
    for(auto i=0; i<A.size(); i++)
    {
        if(A[i][0] <= B && A[i][col-1] >= B)
        {
            if(bin_search(A[i], 0, col-1, B))
                return 1;
            else 
                return 0;
        }
    }
    return 0; // O(logn), O(1)
}


# 2nd method


bool searchMatrix(vector<vector<int> > &matrix, int target)
{
    int n = matrix.size(); 
    int m = matrix[0].size();
    
    int l = 0, r = m * n - 1;
    while (l != r)
    {
        int mid = (l + r - 1) >> 1;
        
        if (matrix[mid / m][mid % m] < target)
            l = mid + 1;
            
        else 
            r = mid;
    }
    
    return matrix[r / m][r % m] == target; // O(logn), O(1)
}



