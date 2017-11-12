/*

https://www.interviewbit.com/problems/3-sum-zero/


Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2) 

*/



vector<vector<int> > Solution::threeSum(vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int>> v;

    if(A.size() < 3)
        return  vector<vector<int>>();

    sort(A.begin(), A.end());

    for(auto i=0; i<A.size(); i++)
    {
        int l = i+1, r = A.size()-1;
        int targ = -A[i];
        
        while(l < r)
        {
            int sum = A[l] + A[r];
            
            if(sum < targ)
                l++;
            
            else if(sum > targ)
                r--;
            
            else
            {
                vector<int> triplet(3, 0);
                triplet[0] = A[i];
                triplet[1] = A[l];
                triplet[2] = A[r];
                
                v.push_back(triplet);
                
                // process duplicates of num 2
                while(l < r && A[l] == triplet[1]) 
                    l++;
                // process duplicates of num 3
                while(l < r && A[r] == triplet[2])
                    r--;
            }
        }
        // process duplicates of num 1
        while(i+1 < A.size() && A[i+1] == A[i])
            i++;
    }


    return v;
    
}


