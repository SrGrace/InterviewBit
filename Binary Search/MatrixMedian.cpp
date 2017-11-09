/*

https://www.interviewbit.com/problems/matrix-median/


Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. Assume N*M is odd.

For example,

Matrix=
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

Median is 5. So, we return 5.

Note: No extra memory is allowed.

*/




int Solution::findMedian(vector<vector<int> > &A) 
{
    int r = A.size(), c = A[0].size(), min = A[0][0], max = A[0][0];
    
    for(auto i=0; i<r; i++)
    {
        if(A[i][0] < min)  // find min
            min =  A[i][0];
            
        if(A[i][c-1] > max)  // find max;
            max = A[i][c-1];
    }
    
    int targ = (r*c+1)/2;
    
    while(min < max)
    {
        int mid = min + (max - min)/2;
        int idx = 0;
        
        // Find count of elements smaller than mid
        for(auto i=0; i<r; i++)
        {
            idx += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        
        if(idx < targ)
            min = mid + 1;
        else
            max = mid;
        
    }
    return min;
}





