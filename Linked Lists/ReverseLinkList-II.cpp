/*

https://www.interviewbit.com/problems/reverse-link-list-ii/


Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

    Note:
    Given m, n satisfy the following condition:
    1 ≤ m ≤ n ≤ length of list.

    Note 2:
    Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(!A) 
        return NULL;
    
    ListNode *dummy = new ListNode(0);
    dummy->next = A;
    ListNode *prev = dummy;
    
    for(auto i=0; i<m-1; i++)
        prev = prev->next;
        
    ListNode *st = prev->next;
    ListNode *ed = st->next;
    
    for(auto i=0; i<n-m; i++)
    {
        st->next = ed->next;
        ed->next = prev->next;
        prev->next = ed;
        ed = st->next;
    }
    
    return dummy->next;
}




