/*

https://www.interviewbit.com/problems/single-number-ii/



Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4

*/



# 1st method


int Solution::singleNumber(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int x = 0, y = 0;
    for(auto it : A)
    {
        x = (x^it) & ~y;
        y = (y^it) & ~x;
        
    }
    
    return x;
}


# 2nd method


int Solution::singleNumber(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int a = 0, b = 0, t = 0;
    
    for(auto c : A)
    {
        t = a&~b&~c | ~a&b&c;
        b = ~a&b&~c | ~a&~b&c;
        a = t;
    }

    return a|b;
}




