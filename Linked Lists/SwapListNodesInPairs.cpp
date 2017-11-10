/*

https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/


Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode *k_reverse(ListNode *A, int k)
{
    ListNode *nxt = NULL, *tmp = NULL, *curr = A;
    int cnt = 0;
    
    while(curr && cnt < k)
    {
        nxt = curr->next;
        curr->next = tmp;
        tmp = curr;
        curr = nxt;
        
        cnt++;
    }
    
    if(nxt)
        A->next = k_reverse(nxt, k);
        
    return tmp;
}
ListNode* Solution::swapPairs(ListNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int k = 2;
    
    return k_reverse(A, k);
}



