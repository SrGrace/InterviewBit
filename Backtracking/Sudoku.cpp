/*

https://www.interviewbit.com/problems/sudoku/

https://leetcode.com/problems/sudoku-solver/description/


Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'

You may assume that there will be only one unique solution.

*/




bool check(vector<vector<char>>& A, int r, int c, char val)
{
    int boxstartrow = r-r%3, boxstartcol = c-c%3;
    
    // usedinrow
    for(int i=0; i<9; i++)
    {
        if(A[i][c] == val)
            return false;
    }
    
    // usedincol
    for(int i=0; i<9; i++)
    {
        if(A[r][i] == val)
            return false;
    }
    
    // usedinbox
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(A[i + boxstartrow][j + boxstartcol] == val)
                return false;
        }
    }
    
    return true;       
}
bool soln(vector<vector<char>>& A, int r, int c)
{
    if(r == 9) 
        return true;
    
    if(c == 9) 
        return soln(A, r+1, 0);
    
    if(A[r][c] != '.') 
        return soln(A, r, c+1);
    
    for(char ch='1'; ch<='9'; ch++)
    {
        if(check(A, r, c, ch))
        {
            A[r][c] = ch;
            
            if(soln(A, r, c+1))
                return true;              
            A[r][c] = '.';
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    soln(A, 0, 0);
    
}


