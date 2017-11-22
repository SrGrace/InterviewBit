/*

https://www.interviewbit.com/problems/symmetric-binary-tree/


Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3

The above binary tree is symmetric.
But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

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
 
int isMirror(TreeNode *A, TreeNode *B)
{
    if(!A && !B)
        return 1;
        
    if(A && B && A->val == B->val)
        return (isMirror(A->left, B->right) && isMirror(A->right, B->left));
        
    return 0;
}
int Solution::isSymmetric(TreeNode* A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return isMirror(A, A);    
}


