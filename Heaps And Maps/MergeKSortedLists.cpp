/*

https://www.interviewbit.com/problems/merge-k-sorted-lists/



Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9

will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20

*/





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
struct cmpr {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};


ListNode* Solution::mergeKLists(vector<ListNode*> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    priority_queue<ListNode*, vector<ListNode*>, cmpr> pq;
    
    ListNode head(0);
    ListNode *curr=&head;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i]) pq.push(A[i]);
    }
    
    while(!pq.empty())
    {
        curr->next=pq.top();
        pq.pop();
        
        curr=curr->next;
        if(curr->next) pq.push(curr->next);
    }
    
    return head.next;
}







