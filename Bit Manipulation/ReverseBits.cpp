/*

https://www.interviewbit.com/problems/reverse-bits/

Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000

return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000

return 3221225472


*/


unsigned int Solution::reverse(unsigned int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    unsigned int B = 0;
    
    for(auto i=0; i<32; i++)
    {
        B = (B<<1) + (A>>i & 1);
    }
    
    return B;
}




