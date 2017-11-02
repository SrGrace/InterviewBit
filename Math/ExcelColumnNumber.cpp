/*

https://www.interviewbit.com/problems/excel-column-number/


Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 

*/


int Solution::titleToNumber(string A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int res=0;
   
    for(auto ch : A)
    {
        res *= 26;
        res += ch-'A'+1;
    }
    return res;
}




