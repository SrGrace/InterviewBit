/*

https://www.interviewbit.com/problems/power-of-two-integers/


Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 

*/



bool Solution::isPower(int A) 
{
    if(A < 2) return true;
    
    for(auto i=2; i*i<=A; i++)
    {
        if(A%i==0) 
        {
            for(auto j=2; j<=32; j++) // since 32 bit signed num can contain atmost x^32 range in base x number system
            { 
                if(pow(i,j) == A) return true;
            }
        }
    }
    return false;
}



