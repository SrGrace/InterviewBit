/*

https://www.interviewbit.com/problems/single-number/


Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example :

Input : [1 2 2 3 1]
Output : 3

*/


int Solution::singleNumber(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int x = 0;
    for(auto it : A)
    {
        x ^= it;
    }
    return x;
    
}




