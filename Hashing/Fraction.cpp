/*

https://www.interviewbit.com/problems/fraction/


Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"

*/



string Solution::fractionToDecimal(int numerator, int denominator)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    long num = (long) numerator;
    long den = (long) denominator;
    
    if(!num)
        return "0";
    string s;
    
    // determine sign
    if(num < 0 ^ den < 0)
        s += '-';
        
    num = abs(num);
    den = abs(den);
    
    s += to_string(num/den);
    
    long rem = num%den;
    
    if(!rem)
        return s;
        
    s += '.';
    rem *= 10;
    
    map<long, long> mp;
    
    while(rem)
    {
        long q = rem/den;
        if(mp.find(rem) != mp.end())
        {
            s.insert(mp[rem], 1, '(');
            s += ')';
            break;
        }
        mp[rem] = s.size();
        s += to_string(q);
        rem = (rem%den)*10;
    }
    
    return s;
    
}


