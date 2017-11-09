/*

https://www.interviewbit.com/problems/merge-two-sorted-lists/


Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15

The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(!A)
        return B;
    if(!B)
        return A;
    
    ListNode *res;
    
    if(A->val <= B->val)
    {
        res = A;
        res->next = mergeTwoLists(A->next, B);
    }
    else
    {
        res = B;
        res->next = mergeTwoLists(B->next, A);
    }
    
    return res;
    
}


