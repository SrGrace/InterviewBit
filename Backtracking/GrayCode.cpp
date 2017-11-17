/*

https://www.interviewbit.com/problems/gray-code/



The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

There might be multiple gray code sequences possible for a given n.
Return any such sequence.

*/


vector<int> Solution::grayCode(int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> res;
    res.push_back(0);
    
    for(auto i=0; i<A;i++)
    {
        int sz = res.size();
        for(auto j=sz-1; j>=0; j--)
        {
            res.push_back(res[j] + (1<<i));
        }
    }
    
    return res;
}


