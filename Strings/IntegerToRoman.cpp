/*

https://www.interviewbit.com/problems/integer-to-roman/


Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Input is guaranteed to be within the range from 1 to 3999.

Example :

Input : 5
Return : "V"

Input : 14
Return : "XIV"

    Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output”

    For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 
    
 */
 
 
 
 string Solution::intToRoman(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // for thousands
    string m[] = {"", "M", "MM", "MMM"};
    
    // for hundreds
    string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    
    // for tens
    string x[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    
    // for ones
    string i[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    string thou = m[A/1000];
    string hund = c[(A%1000)/100];
    string tens = x[(A%100)/10];
    string ones = i[A%10];
    
    string iToR = thou + hund + tens + ones;
    
    return iToR;
}


