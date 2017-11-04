/*

https://www.interviewbit.com/problems/next-permutation/


Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50

Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

    Warning : DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION.

    Use of Library functions will disqualify your submission retroactively and will give you penalty points. 
    
 */
 
 
 
 void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int idx = -1;
    
    for(auto i=A.size()-1; i>=0; --i)
    {
        if(A[i] > A[i-1])
        {
            idx = i-1;
            break;
        }
    }
    
    if(idx != -1)   // if permutation exists
    {
        int i = A.size()-1;
        while(A[i] < A[idx])    //find the number which is just greater
        {
            --i;
        }
        swap(A[i], A[idx]);
    }
    
    int i = idx+1;  
    int j = A.size()-1;
    
    while(i < j)   //now just reverse the nums from the (k+1)th position to get the next permutation 
    {
        swap(A[i++], A[j--]);
    }
    
}


