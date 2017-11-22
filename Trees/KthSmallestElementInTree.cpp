/*

https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/


Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.

    NOTE : You may assume 1 <= k <= Total number of nodes in BST 

*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode *kthSmall(TreeNode *root, int k, int *cnt)
{
    if(!root)
        return NULL;
    
    TreeNode *lft = kthSmall(root->left, k, cnt);
    
    if(lft)
        return lft;
    
    if(++(*cnt) == k)
        return root;
        
    return kthSmall(root->right, k, cnt);
}
 
int Solution::kthsmallest(TreeNode* root, int k) 
{
    int cnt = 0;
    
    return kthSmall(root, k, &cnt)->val;
    
}


