/*

https://www.interviewbit.com/problems/largest-number/



Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/



bool cmpr(string x, string y)
{
    return x+y > y+x;
}

string Solution::largestNumber(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<string> v;
    
    bool zero=true;
    
    for(auto i=0; i<A.size(); i++)
    {
        v.push_back(to_string(A[i]));
        
        if(A[i] != 0) 
        {
            zero=false;
        }
    }
    
    if(zero) return "0";
    
    sort(v.begin(), v.end(), cmpr);
    
    string s = "";
    
    for(auto it : v)
    {
        s += it;
    }
    
    return s; // O(nlogn), O(n)
    
}



