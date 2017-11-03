/*

https://www.interviewbit.com/problems/maximum-consecutive-gap/



Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 

Return 0 if the array contains less than 2 elements.

    You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    You may also assume that the difference will not overflow.
  
*/


int Solution::maximumGap(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

// overflow (Don't know why)
    /*
    int n = A.size(), gap = 0;
    
    if(n <= 1) return 0;
    
    int maxE = *max_element(A.begin(), A.end());
    int minE = *min_element(A.begin(), A.end());
    
    int len = (maxE-minE)/(n-1);
    
    if(len ==0) return maxE-minE;
    
    vector<int> maxA(n, -1);
    vector<int> minA(n, -1);
    
    for(auto i=0; i<n; i++)
    {
        int idx = (A[i]-minE)/len;
        if(minA[idx] < 0)
        {
            minA[idx] = A[i];
            maxA[idx] = A[i];
            
        }
        else 
        {
            maxA[idx] = max(maxA[idx], A[i]);
            minA[idx] = min(minA[idx], A[i]);
        }
    }
    
    //int prev = maxA[0];
    int k=0;
    for(auto i=0; i<minA.size(); i++)
    {
        if(minA[i] >= 0) 
        {
            gap = max(gap, minA[i]-maxA[k]);
            k = i;
        }
    }
    
    return gap;
    */
    
    
    
    if(A.size() < 2){
        return 0;
    }
    
    vector<int> maxA(A.size(), -1);
    vector<int> minA(A.size(), -1);
    
    int mini = INT_MAX, maxi = INT_MIN;
    int gap = 0, bucket = 0, ind = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] < mini){
            mini = A[i];
        }
        if(A[i] > maxi){
            maxi = A[i];
        }
    }
    
    gap = maxi - mini;
    gap = gap/(A.size()-1);
    
    if(gap == 0){
        return maxi - mini;
    }
    
    for(int i = 0; i < A.size(); i++)
    {
        bucket = (int)((A[i] - mini)/gap);
        if(minA[bucket] < 0)
        {
            minA[bucket] = A[i];
            maxA[bucket] = A[i];
        }
        else
        {
            minA[bucket] = min(A[i], minA[bucket]);
            maxA[bucket] = max(A[i], maxA[bucket]);
        }
    }
    
    int max_gap = 0;
    
    for(int i = 0; i < minA.size(); i++)
    {
        if(minA[i] >= 0)
        {
            max_gap = max(max_gap, minA[i]-maxA[ind]);
            ind = i;
        }    
    }
    
    return max_gap;
}


