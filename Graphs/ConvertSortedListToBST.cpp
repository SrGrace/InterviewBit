/*

https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/


Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : 1 -> 2 -> 3
A height balanced BST  :

      2
    /   \
   1     3


*/



# 1st method ( O(nlogn) ) (top to bottom)


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
TreeNode* toBst(ListNode *head, ListNode *tail)
{
    if(head == tail)
        return NULL;
        
    ListNode *slow = head, *fast = head;
    
    while(fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    TreeNode *root = new TreeNode(slow->val);
    
    root->left = toBst(head, slow);
    root->right = toBst(slow->next, tail);
    
    return root;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(!A)
        return NULL;
    
    return toBst(A, NULL);
    
}



# 2nd method ( O(n) ) (bottom-up)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// find lenght of the list
int cnt(ListNode *head)
{
    int sz = 0;
    while(head)
    {
       sz++;
       head = head->next;
    }
    return sz;
}

ListNode *list;

TreeNode* toBst(int n)
{
    if(n == 0)
        return NULL;
 
    TreeNode *root = new TreeNode(0);
    
    root->left = toBst(n/2);
    
    root->val = list->val;
    list = list->next;
    
    root->right = toBst(n - n/2 - 1);
    
    return root;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(!A)
        return NULL;
        
    list = A;
    
    return toBst(cnt(A));
    
}



