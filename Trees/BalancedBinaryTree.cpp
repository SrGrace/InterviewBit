/*

https://www.interviewbit.com/problems/balanced-binary-tree/


Given a binary tree, determine if it is height-balanced.

    Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ 
    by more than 1. 

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 

*/


// bottom up manner

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int dfs_height(TreeNode *A)
{
    if(!A)
        return 0;
    
    int lft = dfs_height(A->left);
    int rgt = dfs_height(A->right);
    
    if(lft == -1)
        return -1;
    if(rgt == -1)
        return -1;
    if(abs(lft - rgt) > 1)
        return -1;
        
    return 1 + max(lft, rgt);
}
int Solution::isBalanced(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return dfs_height(A) != -1;
    
}


