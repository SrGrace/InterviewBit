/*

https://www.interviewbit.com/problems/majority-element/



Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 

*/



int Solution::majorityElement(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int major, cnt = 0;
    
    for(auto i=0; i<A.size(); i++)
    {
        if(!cnt)
        {
            major = A[i];
            cnt = 1;
        }
        else
        {
            if(A[i] == major)
                cnt++;
            else    
                cnt--;
        }
    }
    
    return major;
}



