/*

https://www.interviewbit.com/problems/add-one-to-number/



Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

*/


// # 1st method (May contains leading 0's)


vector<int> Solution::plusOne(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    for(int i=n-1; i>=0; i--)
    {
        if(A[i] < 9) 
        {
            A[i]++;
            return A;
        }

        A[i] = 0;
    }

    vector<int> v(n+1);
    v[0] = 1;

    return v; // O(n), O(1)
    
}



// # 2nd method


vector<int> Solution::plusOne(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int carry=1;
    vector<int> v;
    
    for(int i=A.size()-1;i>=0;--i)
    {
        int sum;
        sum=A[i]+carry;
        carry=sum/10;
        v.push_back(sum%10);
    }
    
    v.push_back(carry);
    int i=v.size()-1;
    
    vector<int> res;
    while(i>=0 && v[i]==0)
    {
        i--;
    }
    
    while(i>=0)
    {
        res.push_back(v[i]);
        i--;
    }
    
    return res; // O(n), O(n)
}


