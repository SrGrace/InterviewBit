/*

https://www.interviewbit.com/problems/divide-integers/


Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2

Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

*/




int Solution::divide(int dividend, int divisor) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(dividend == 0 || divisor == 1) 
        return dividend;
    else if(divisor == 0 || (divisor == -1 && dividend == INT_MIN))
        return INT_MAX;
            
    int res = 0;
    
    bool isNeg = false;
         
    if((dividend^divisor) < 0) isNeg = true;
     
    long x = abs((long)dividend);
    long y = abs((long) divisor);
     
    while(x >= y)
    {
        int k = 1;
        
        while((y<<k) >= (y<<k-1) && (x-(y<<k)) >= 0) 
            k++;
        res += (1<<k-1);
        
        x = x-(y<<k-1);
    }
    
    if(isNeg) return -1*res;
    
    return res;
}




