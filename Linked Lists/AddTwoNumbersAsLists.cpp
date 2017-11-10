/*

https://www.interviewbit.com/problems/add-two-numbers-as-lists/


You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807

Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    int carry = 0;
    
    while(A || B || carry)
    {
        int sum = (A ? A->val : 0) + (B ? B->val : 0) + carry;
        carry = sum/10;
        
        curr->next = new ListNode(sum%10);
        curr = curr->next;
        
        A = A ? A->next : A;
        B = B ? B->next : B;
    }
    
    return dummy->next;
    
}



