/*

https://www.interviewbit.com/problems/evaluate-expression/



Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/


# 1st Method


int Solution::evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    string s = A.back();
    A.pop_back();
    
    if(s == "*" or s == "/" or s == "+" or s == "-")
    {
        int op2 = evalRPN(A);
        int op1 = evalRPN(A);
        
        if(s == "*")
            return op1*op2;
        if(s == "/")
            return op1/op2;
        if(s == "+")
            return op1+op2;
        if(s == "-")
            return op1-op2;
        
    }
    else
        return atoi(s.c_str());
          
}


# 2nd Method


int Solution::evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<int> st;
    
    for(int i = 0; i < A.size(); ++i) 
    {
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/") 
        {
            int v1=st.top();
            st.pop();
            
            int v2=st.top();
            st.pop();
            
            switch(A[i][0]) 
            {
                case '+':
                    st.push(v2 + v1);
                    break;
                case '-':
                    st.push(v2 - v1);
                    break;
                case '*':
                    st.push(v2 * v1);
                    break;
                case '/':
                    st.push(v2 / v1);
                    break;
            }
        } 
        else 
        {
            st.push(atoi(A[i].c_str()));
        }
    }
    
    return st.top();    
}



