/*

https://www.interviewbit.com/problems/excel-column-title/


Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

*/


string Solution::convertToTitle(int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    string s="";
    
    while(A > 0)
    {
        A--;
        s=char(A%26+'A')+s;
        A/=26;
    }
    return s; // O(log26(A)), O(log26(A))
}



