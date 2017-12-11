/*

https://www.interviewbit.com/problems/n3-repeat-number/



You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time 
and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 

*/




# Solution Approach (Boyer-Moore Majority Vote algorithm)
 
The essential concepts is you keep a counter for the majority number X. If you find a number Y that is not X, 
the current counter should deduce by 1. The reason is that if there is 5 X and 4 Y, there would be one (5-4) more X than Y. 
This could be explained as "4 X being paired out by 4 Y".

And since the requirement is finding the majority for more than ceiling of [n/3], 
the answer would be less than or equal to two numbers.
So we can modify the algorithm to maintain two counters for two majorities.



int Solution::repeatedNumber(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    int cnt1 = 0, cnt2 = 0, x = 0, y = 1;
    
    for(auto it : A)
    {
        if(it == x) 
            cnt1++;
        else if(it == y) 
            cnt2++;
        
        else if(cnt1 == 0)
        {
            x = it;
            cnt1 = 1;
        }
        else if(cnt2 == 0)
        {
            y = it;
            cnt2 = 1;
        }
        else 
        {
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1 = cnt2 = 0;
    for(auto it : A)
    {
        if(it == x) 
            cnt1++;
        else if(it == y) 
            cnt2++;
    }
    
    if(cnt1 > n/3) 
        return x;
    else if(cnt2 > n/3) 
        return y;
    else 
        return -1;
        
}



