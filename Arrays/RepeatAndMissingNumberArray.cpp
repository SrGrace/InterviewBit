/*

https://www.interviewbit.com/problems/Repeat-And-Missing-Number-Array/


You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

*/

# Approach

/*

    Sum(Actual) = Sum(1...N) + A - B

    Sum(Actual) - Sum(1...N) = A - B. 

    Sum(Actual Squares) = Sum(1^2 ... N^2) + A^2 - B^2

    Sum(Actual Squares) - Sum(1^2 ... N^2) = (A - B)(A + B) = (Sum(Actual) - Sum(1...N)) ( A + B). 
    
We can use the above 2 equations to get the value of A and B.

*/


vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> res;
    long long n = A.size(), x = 0, y = 0;
    
    long long sum = (n*(n+1))/2;
    
    long long sumSq = (n*(n+1)*(2*n+1))/6;
    
    for(int i=0; i<n; i++)
    {
        sum -= (long long)A[i];
        sumSq -= (long long)A[i]*(long long)A[i];
    }
    
    y = (sum + sumSq/sum)/2;
    x = y-sum;
    
    res.push_back(x);   // repeat
    res.push_back(y);   // missing
    
    return res;
}


