/*

https://www.interviewbit.com/problems/painters-partition-problem/


You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much 
time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that 
any painter will only paint contiguous sections of board.

        * 2 painters cannot share a board to paint. That is to say, a board
          cannot be painted partially by one painter, and partially by another.
          
        * A painter will only paint contiguous boards. Which means a
          configuration where painter 1 paints board 1 and 3 but not 2 is
          invalid.

Return the ans % 10000003

Input :
K : Number of painters
T : Time taken by painter to paint 1 unit of board
L : A List which will represent length of each board

Output:
     return minimum time to paint all boards % 10000003

Example

Input : 
  K : 2
  T : 5
  L : [1, 10]

Output : 50

*/

# Solution Approach

# https://articles.leetcode.com/the-painters-partition-problem-part-ii/


int getMax(vector<int> &A)
{
    int max = INT_MIN;
    for(auto i=0; i<A.size(); i++)
        if(A[i] > max)
            max = A[i];
    
    return max;
}
long long getSum(vector<int> &A)
{
    long long sum = 0;
    for(auto i=0; i<A.size(); i++)
        sum += A[i];
    
    return sum;
}
int getReqPainters(vector<int> &A, int maxLenPerPainter)
{
    long long tot = 0; int numPainters = 1;
    for(auto i=0; i<A.size(); i++)
    {
        tot += A[i];
        if(tot > maxLenPerPainter)
        {
            tot = A[i];
            numPainters++;
        }
    }
    
    return numPainters;
}

int Solution::paint(int A, int B, vector<int> &C) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    long long l = getMax(C);
    long long h = getSum(C);
    
    while(l < h)
    {
        long long mid = l + (h - l)/2;
        int reqPainters = getReqPainters(C, mid);
        if(reqPainters <= A)
            h = mid;
        else
            l = mid + 1;
    }
    return ((long long)(l*B))%10000003;
}




