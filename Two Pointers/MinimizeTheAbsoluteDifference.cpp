/*

https://www.interviewbit.com/problems/minimize-the-absolute-difference/



Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]

Output:

1

Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.


*/


# 1st method


int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) 
{
    int ans = INT_MAX;
    
    int i = A.size()-1, j = B.size()-1, k = C.size()-1;
    
    while(i>=0 and j>=0 and k>=0)
    {
        int maxE = max(A[i], max(B[j],C[k]));
        
        int minE = min(A[i], min(B[j],C[k]));
        
        ans = min(ans, maxE - minE);
        
        if(A[i] == maxE) i--;
        
        else if(B[j] == maxE) j--;
        
        else if(C[k] == maxE) k--;
    }
    
    return ans;
    
}


# 2nd method 


vector<int> findClosest(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int p = A.size(), q = B.size(), r = C.size();
    
    int diff = INT_MAX;  // Initialize min diff
 
    // Initialize result
    int res_i =0, res_j = 0, res_k = 0;
 
    // Traverse arrays
    int i=0,j=0,k=0;
    while (i < p && j < q && k < r)
    {
        // Find minimum and maximum of current three elements
        int minimum = min(A[i], min(B[j], C[k]));
        int maximum = max(A[i], max(B[j], C[k]));
 
        // Update result if current diff is less than the min
        // diff so far
        if (maximum-minimum < diff)
        {
             res_i = i, res_j = j, res_k = k;
             diff = maximum - minimum;
        }
 
        // We can't get less than 0 as values are absolute
        if (diff == 0) break;
 
        // Increment index of array with smallest value
        if (A[i] == minimum) i++;
        else if (B[j] == minimum) j++;
        else k++;
    }
 
    // Print result
    vector<int> v;
    
    v.push_back(A[res_i]); 
    v.push_back(B[res_j]);
    v.push_back(C[res_k]);
    
    return v;
    
}



int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) 
{
    vector<int> v = findClosest(A, B, C);
    
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());
    
    return max-min;
    
}


