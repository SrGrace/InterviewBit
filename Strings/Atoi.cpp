/*

https://www.interviewbit.com/problems/atoi/


Please Note:

There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9

Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

    Questions:

    Q1. Does string contain whitespace characters before the number?
    A. Yes

    Q2. Can the string have garbage characters after the number?
    A. Yes. Ignore it.

    Q3. If no numeric character is found before encountering garbage characters, what should I do?
    A. Return 0.

    Q4. What if the integer overflows?
    A. Return INT_MAX if the number is positive, INT_MIN otherwise. 

Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.

*/


bool isNumeric(char ch)
{
    return (ch >= '0' && ch <= '9') ? true : false;
}

int Solution::atoi(const string &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    int res = 0, sign = 1, i = 0;
    
    while(A[i] == ' ') 
        i++;
    
    if(A[0] == '-' || A[0] == '+')
    {
        if(A[i++] == '-') 
            sign = -1;
        else 
            sign = 1;
    }
    
    while(isNumeric(A[i]))
    {
        if(res > INT_MAX/10 || (res == INT_MAX/10 && A[i]-'0' > 7))
        {
            if(sign == 1)
                return INT_MAX;
            else return INT_MIN;
        }
        
        res = res*10 + (A[i++]-'0');
    }
    
    return sign*res;
    
}


