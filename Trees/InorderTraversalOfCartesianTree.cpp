/*

https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/


Given an inorder traversal of a cartesian tree, construct the tree.

    Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 

    Note: You may assume that duplicates do not exist in the tree. 

Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1

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

TreeNode* tree(vector<int> &A, int st, int ed)
{
    if(st > ed)
        return NULL;
    
    int max = A[st], idx = st;
    for(auto i=st; i<=ed; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
            idx = i;
        }
    }
    
    TreeNode *root = new TreeNode(max);
    root->left = tree(A, st, idx-1);
    root->right = tree(A, idx+1, ed);
    
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return tree(A, 0, A.size()-1);
    
}




