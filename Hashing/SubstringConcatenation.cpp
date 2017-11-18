/*

https://www.interviewbit.com/problems/substring-concatenation/

https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/


You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

*/




class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string , int> mp;
        vector<int> idx;
        
        for(auto w : words)
            mp[w]++;
        
        int n = s.size(), m = words.size(), len = words[0].size();
        
        for(auto i=0; i<n-m*len+1; i++)
        {
            int j;
            unordered_map<string, int> seen;
            for(j=0; j<m; j++)
            {
                string w = s.substr(i+j*len, len);
                if(mp.find(w) != mp.end())
                {
                    seen[w]++;
                    if(seen[w] > mp[w])
                        break;
                }
                else
                    break;
            }
            if(j == m)
                idx.push_back(i);
                
        }
        return idx;
    }
};


