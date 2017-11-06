/*

https://www.interviewbit.com/problems/reverse-the-string/


Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

        A sequence of non-space characters constitutes a word.
        Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
        If there are multiple spaces between words, reduce them to a single space in the reversed string.

*/




void Solution::reverseWords(string &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


    reverse(A.begin(), A.end());
    int storeidx = 0;
    for(auto i=0; i<A.size(); i++)
    {
        if(A[i] != ' ')
        {
            if(storeidx != 0)
                A[storeidx++]=' ';
                
            int j = i;
            
            while(j < A.size() && A[j] != ' ')
                A[storeidx++] = A[j++];
            
            reverse(A.begin() + storeidx - (j - i), A.begin() + storeidx);
            i = j;
        }
    }
    A.erase(A.begin() + storeidx, A.end());
    
}



