/*

https://www.interviewbit.com/problems/valid-sudoku/



Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.

The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]

A partially filled sudoku which is valid.

    Note:

        A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem


*/


int Solution::isValidSudoku(const vector<string> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    int row[9][9] = {0}, col[9][9] = {0}, cube[9][9] = {0};
            
    for(auto i=0; i<A.size(); i++)
    {
        for(auto j=0; j<A.size(); j++)
        {
            if(A[i][j] != '.')
            {
                int ch = A[i][j] - '0' - 1;
                int k = i/3 * 3 + j/3;
            
                if(row[i][ch]++ || col[j][ch]++ || cube[k][ch]++)
                    return false;
            }
            
        }
    }

    return true;
}


