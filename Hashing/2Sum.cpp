/*

https://www.interviewbit.com/problems/2-sum/


Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note 
that your returned answers (both index1 and index2 ) are not zero-based.
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make 
things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, 
choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2

*/


vector<int> Solution::twoSum(const vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> v;
        
    if(A.size() < 2)
        return vector<int> ();
    
    map<int, int> mp;
    
    
    for(int i=0; i<A.size(); i++)
    {
        int k = B - A[i];
        
        if(mp.find(k) != mp.end())
        {
            v.push_back(mp[k]+1);
            v.push_back(i+1);
            
            return v;

        }
        if(mp.find(A[i]) == mp.end())
        {
            mp[A[i]] = i;
        }
    }
    
    return v;
}


