/*

https://www.interviewbit.com/problems/colorful-number/


For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different

Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

*/




int Solution::colorful(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    string s = to_string(A);
    map<long long, bool> mp;
    
    for(auto i=0; i<s.size(); i++)
    {
        long long mul = 1;
        
        for(auto j=i; j<s.size(); j++)
        {
            mul *= (long long)(s[j]-'0');
        
            if(mp.find(mul) != mp.end())
                return 0;
            
            mp[mul] = true;
        }
    }
    
    return 1;
    
}




