/*

https://www.interviewbit.com/problems/list-cycle/


Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(!A || !A->next)
        return NULL;
    
    ListNode *slwptr = A, *fstptr = A;
    bool isCycle = false;
    
    while(slwptr && fstptr && fstptr->next)
    {
        slwptr = slwptr->next;
        fstptr = fstptr->next->next;
        
        if(slwptr == fstptr)
        {
            isCycle = true;
            break;
        }
    }

    if(!isCycle)
        return NULL;
        
    slwptr = A;
    
    while(slwptr != fstptr)
    {
        slwptr = slwptr->next;
        fstptr = fstptr->next;
    }
    
    return slwptr;
}


# OR


ListNode* Solution::detectCycle(ListNode* A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode *slow, *fast, *st;

    slow = fast = head;
    
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            st = head;

            while (slow != st)
            {
                st = st->next;
                slow = slow->next;
                return st;
            }
         }
    }
    
    return NULL;
    
}


