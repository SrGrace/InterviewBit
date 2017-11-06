/*

https://www.interviewbit.com/problems/roman-to-integer/


Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System

Example :

Input : "XIV"
Return : 14

Input : "XX"
Output : 20

*/



int val(char c)
{
    if(c == 'I') return 1;
    if(c == 'V') return 5;
    if(c == 'X') return 10;
    if(c == 'L') return 50;
    if(c == 'C') return 100;
    if(c == 'D') return 500;
    if(c == 'M') return 1000;
    
    return -1;
}

int Solution::romanToInt(string A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int res = 0;
    
    for(auto i=0; i<A.size(); i++)
    {
        int s1 = val(A[i]);
        
        if(i+1 < A.length())
        {
            int s2 = val(A[i+1]);
            if(s1 >= s2)
                res += s1;
            else
            {
                res += (s2 - s1);
                i++;
            }
        }
        else 
        {
            res += s1;
            i++;
        }
    }
    
    return res;
}




