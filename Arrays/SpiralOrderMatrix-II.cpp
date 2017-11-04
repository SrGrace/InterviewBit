/*

https://www.interviewbit.com/problems/spiral-order-matrix-ii/


Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]

*/



vector<vector<int> > Solution::generateMatrix(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> >v(A, vector<int>(A));
    int i = 0, j, k = 1;
    
    while(k <= A*A)
    {
        j = i;
        
        while(j < A-i)   //1. horizonal, left to right
        {
            v[i][j++] = k++;
        }
        
        j = i+1;
        while(j < A-i)   //2. vertical, top to bottom
        {
            v[j++][A-i-1] = k++;
        }
        
        j = A-i-2;
        while(j > i)     //3. horizonal, right to left 
        {
            v[A-i-1][j--] = k++;
        }
        
        j = A-i-1;
        while(j > i)     //4. vertical, bottom to  top 
        {
            v[j--][i] = k++;
        }
        
        i++;    // next loop
      
    }
    
    return v;
    
}


