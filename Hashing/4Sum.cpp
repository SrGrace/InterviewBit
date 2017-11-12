/*

https://www.interviewbit.com/problems/4-sum/


Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique 
quadruplets in the array which gives the sum of target.

    Note:

        Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
        The solution set must not contain duplicate quadruplets.

Example :
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)

Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... 
Solution[i][k] < Solution[j][k])

*/



vector<vector<int> > Solution::fourSum(vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int>> v;
    
    if(A.size() < 4)
        return vector<vector<int>>();
        
    sort(A.begin(), A.end());

    for(auto i=0; i<A.size(); i++)
    {
        
        int targ3 = B - A[i];
        
        for(auto j=i+1; j<A.size(); j++)
        {
            int targ2 = targ3 - A[j];
            
            int l = j+1, r = A.size()-1;
            
            while(l < r)
            {
                int two_sum = A[l] + A[r];
                
                if(two_sum < targ2)
                    l++;
                
                else if(two_sum > targ2)
                    r--;
                
                else
                {
                    vector<int> quad(4, 0);
                    quad[0] = A[i];
                    quad[1] = A[j];
                    quad[2] = A[l];
                    quad[3] = A[r];
                    
                    v.push_back(quad);
                    
                    // process duplicates of num 3
                    while(l < r && A[l] == quad[2]) 
                        l++;
                    // process duplicates of num 4
                    while(l < r && A[r] == quad[3])
                        r--;
                }
            }
            // process duplicates of num 2
            while(j+1 < A.size() && A[j+1] == A[j])
                j++;
                
        }
        // process duplicates of num 1
            while(i+1 < A.size() && A[i+1] == A[i])
                i++;
    }

    return v;
    
}




