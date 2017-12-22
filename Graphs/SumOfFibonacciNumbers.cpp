/*

https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/


How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
Note : repetition of number is allowed.

Example:

N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 

*/


# 1st method ( Greedy Solution )


int Solution::fibsum(int A) 
{
    vector<int> fib;
    int x = 1, y = 1;
    
    while(x <= A)
    {
        fib.push_back(x);
        int tmp = x+y;
        x = y;
        y = tmp;
    }
    
    int cnt = 0;
    
    for(auto i = fib.size()-1; i>=0; i--)
    {
        int k = fib[i];
        
        while(k <= A)
        {
            A -= k;
            cnt++;
        }
        
        if(A == 0)
            break;
    }
    
    return cnt;
}


# 2nd method

-----------



