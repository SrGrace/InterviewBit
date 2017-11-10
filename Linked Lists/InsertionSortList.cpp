/*

https://www.interviewbit.com/problems/insertion-sort-list/


Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(!A) 
        return A;
        
    ListNode *dummy = new ListNode(0); //new starter of the sorted list
    ListNode *curr = A; //the node will be inserted
    ListNode *pre = dummy; //insert node between pre and pre->next
    ListNode *nxt = NULL; //the next node will be inserted
    
    while(curr)
    {
        nxt = curr->next;
        
        //find the right place to insert
        while(pre->next && pre->next->val < curr->val)
        {
            pre = pre->next;
        }
        
        //insert between pre and pre.next
        curr->next = pre->next;
        pre->next = curr;
        pre = dummy;
        curr = nxt;
    }
    
    return dummy->next;
}



