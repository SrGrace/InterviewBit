/*

https://www.interviewbit.com/problems/letter-phone/

https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/



Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Make sure the returned strings are lexicographically sorted.

*/


# method 1 : Itrerative


vector<string> Solution::letterCombinations(string A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    string charMap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> res;

    res.push_back("");

    for(auto i=0; i<A.size() ;i++)
    {
        vector<string> tmp;
        string ch = charMap[A[i] - '0'];

        for(auto j=0; j<ch.size(); j++)
        {
            for(auto k=0; k<res.size(); k++)
            {
                tmp.push_back(res[k] + ch[j]);
            }
        }
        res = tmp;
    }

    sort(res.begin(), res.end());

    return res;
}


# method 2 : Recursive



string charMap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void generateHelper(string &curr, int idx, string &A, vector<string> &ans) 
{
    if (idx == A.length()) 
    {
        ans.push_back(curr);
        return;
    }
    
    int a = A[idx] - '0';
    
    for (int i = 0; i < charMap[a].length(); i++) 
    {
        curr.push_back(charMap[a][i]);
        
        generateHelper(curr, idx + 1, A, ans);
        
        curr.pop_back();
    }
    return;
}

vector<string> Solution::letterCombinations(string A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<string> ans;
    string curr = "";
    
    generateHelper(curr, 0, A, ans);
    
    return ans;
}

