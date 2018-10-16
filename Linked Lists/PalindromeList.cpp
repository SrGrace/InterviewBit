/*

https://www.interviewbit.com/problems/palindrome-list/


Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes: Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.


*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode * tmp;

int check(ListNode *p)
{
    if(!p)
        return 1;
    bool isPal = check(p->next) & (tmp->val == p->val);
    tmp = tmp->next;
    
    return isPal;
}

int Solution::lPalin(ListNode* A) {
    
    tmp = A;
    return check(A);
    
}


