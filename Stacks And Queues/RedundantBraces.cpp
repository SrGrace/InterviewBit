/*

https://www.interviewbit.com/problems/redundant-braces/


Write a program to validate if the input string has redundant braces?
Return 0/1

0 -> NO
1 -> YES

Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0

*/



int Solution::braces(string A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() == 0) return 0;
    
    stack<char> st;
    
    int i = 0;
    
    while(i < A.size())
    {
        char ch = A[i];
        if(ch == '(' or ch == '+' or ch == '-' or ch == '*' or ch == '/')
            st.push(ch);
        else if(ch == ')')
        {
            if(st.top() == '(') 
                return 1;
            else
            {
                while(!st.empty() && st.top() != '(')
                    st.pop();
                st.pop();
                    
            }
        }
        i++;
    }
    return 0;
    
}




