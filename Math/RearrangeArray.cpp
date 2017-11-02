/*

https://www.interviewbit.com/problems/rearrange-array/


Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]

    Lets say N = size of the array. Then, following holds true :

        All elements in the array are in the range [0, N-1]
        N * N does not overflow for a signed integer

*/


# Solution Approach

/*

If we had extra space to do it, the problem will be very easy.
Store a copy of A in B.

And then for every element, do A[i] = B[B[i]]

But we don't so....

1) Increase every Array element Arr[i] by (Arr[Arr[i]] % n)*n.
2) Divide every element by N.

*/



void Solution::arrange(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    for(auto i=0;i<A.size();i++)
    {
        A[i]+=(A[A[i]]%A.size())*A.size();
    }
    
    for(auto i=0;i<A.size();i++)
    {
        A[i]/=A.size();
    }
}





