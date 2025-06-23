/*

https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/


You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum 
characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2

*/


# Approach:

Each index of LPS array contains the longest prefix which is also a suffix. Now take the string and reverse of a string and 
combine them with a sentinal character ($) in between them and compute the LPS array of this combined string. 
Now take the last value of the LPS array (vector<int> lps.back()) and subtract it with the length of the original string, 
This will give us the minimum number of insertions required in the begining of the string. 



vector<int> lps_array(string s)
{
    int n = s.length(), j = 0, i = 1;
    vector<int> lps(n);
    lps[0] = 0;
    
    while(i < n)
    {
        if(s[i] == s[j])
        {
            lps[i] = j+1;
            i++;
            j++;
        }
        else if(j > 0)
            j = lps[j-1];
        else 
        {
            lps[i] = 0;
            i++;
        }
    }
    return lps;
}

int Solution::solve(string A) 
{
    string B = A;
    reverse(B.begin(), B.end());
    
    string concat = A + "$" + B;
    
    vector<int> lps = lps_array(concat);
    
    return (A.size() - lps.back()); // O(n), O(n)
    
}





