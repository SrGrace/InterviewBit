/*

https://www.interviewbit.com/problems/distribute-candy/


There are N children standing in a line. Each child is assigned a rating value.

 You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Sample Input :

Ratings : [1 2]
Sample Output :

3
The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. So rating 2 candidate gets 2
candies. In total, 2+1 = 3 candies need to be given out.

*/



int Solution::candy(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int size = A.size();
        
    if(size <= 1)
        return size;
    
    vector<int> cd(size, 1);
    
    for (int i = 1; i < size; i++)
    {
        if(A[i] > A[i-1])
            cd[i] = cd[i-1] + 1;
    }
    for (int i= size-1; i>0 ; i--)
    {
        if(A[i-1] > A[i])
            cd[i-1] = max(cd[i]+1, cd[i-1]);
    }
    
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum += cd[i];
    }
    
    return sum;
}


