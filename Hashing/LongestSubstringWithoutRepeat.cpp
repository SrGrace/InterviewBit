/*

https://www.interviewbit.com/problems/longest-substring-without-repeat/


Given a string,
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

*/



int Solution::lengthOfLongestSubstring(string A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


    map<char, int> mp;

    int max_l = 0, i = 0;
    
    for(auto j=0; j<A.size(); j++)
    {
        if(mp.find(A[j]) != mp.end())
            i = max(mp[A[j]], i);
            
        max_l = max(max_l, j-i+1);
        mp[A[j]] = j+1;
    }
    
    return max_l;

}


