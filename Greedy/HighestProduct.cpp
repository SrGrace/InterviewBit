/*

https://www.interviewbit.com/problems/highest-product/


Given an array of integers, return the highest product possible by multiplying 3 numbers from the array

Input:

array of integers e.g {1, 2, 3}

    NOTE: Solution will fit in a 32-bit signed integer 

Example:

[0, -1, 3, 100, 70, 50]

=> 70*50*100 = 350000

*/


# 1st method O(nlogn) & O(1)


int Solution::maxp3(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() < 3)
        return -1;
        
    int n = A.size();
        
    sort(A.begin(), A.end());
    
    return max(A[0]*A[1]*A[n-1], A[n-1]*A[n-2]*A[n-3]);
    
}


# 2nd method O(n) & O(1)


int Solution::maxp3(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() < 3)
        return -1;
        
    int n = A.size();
    
    int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;
 
    // Initialize Minimum and second mimimum element
    int minA = INT_MAX, minB = INT_MAX;
 
    for (int i = 0; i < n; i++)
    {
        // Update Maximum, second maximum and third
        // maximum element
        if (A[i] > maxA)
        {
            maxC = maxB;
            maxB = maxA;
            maxA = A[i];
        }
 
        // Update second maximum and third maximum element
        else if (A[i] > maxB)
        {
            maxC = maxB;
            maxB = A[i];
        }
 
        // Update third maximum element
        else if (A[i] > maxC)
            maxC = A[i];
 
        // Update Minimum and second mimimum element
        if (A[i] < minA)
        {
            minB = minA;
            minA = A[i];
        }
 
        // Update second mimimum element
        else if(A[i] < minB)
            minB = A[i];
    }
 
    return max(minA * minB * maxA, maxA * maxB * maxC);
}



