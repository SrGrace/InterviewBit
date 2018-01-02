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
 

# 1st method

 
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
    ListNode *curr = &head;
    
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]) 
           pq.push(A[i]);
    }
    
    while(!pq.empty())
    {
        curr->next = pq.top();
        pq.pop();
        
        curr = ->next;
        if(curr->next) 
           pq.push(curr->next);
    }
    
    return head.next;
}



# 2nd method

# The basic idea is really simple. We can merge first two lists and then push it back. 
# Keep doing this until there is only one list left in vector. Actually,
# we can regard this as an iterative divide-and-conquer solution.


ListNode *merge2lists(ListNode *l1, ListNode *l2)
{
    if(l1 == nullptr) 
       return l2;
 
    if(l2 == nullptr) 
       return l1;
 
    if(l1->val <= l2->val)
    {
       l1->next = merge2lists(l1->next, l2);
       return l1;
    }
 
    else
    {
       l2->next = merge2lists(l2->next, l1);
       return l2;      
    }
}


ListNode* Solution::mergeKLists(vector<ListNode*> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() == 0) return nullptr;
 
    while(A.size() > 1)
    {
        A.push_back(merge2lists(A[0], A[1]));
        A.erase(A.begin());
        A.erase(A.begin());
    }
 
    return A.front();
 
 
}





