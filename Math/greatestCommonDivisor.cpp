/*

https://www.interviewbit.com/problems/greatest-common-divisor/



Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3 

    NOTE : DO NOT USE LIBRARY FUNCTIONS 

*/


int Solution::gcd(int A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    while (B != 0)  
    {
        int t = B;
        B = A % B;
        A = t;
    }
    
    return A;
}



