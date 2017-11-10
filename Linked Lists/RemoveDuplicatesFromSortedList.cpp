/*

https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/


Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode *curr = A;
    while(curr && curr->next)
    {
        if(curr->val == curr->next->val)
        {
            curr->next = curr->next->next;
        }
        else
            curr = curr->next;
    }
    
    return A;
}



