/*

https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/


Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Note that the left child of all nodes should be NULL.

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
 
 
TreeNode* Solution::flatten(TreeNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(!A)
        return NULL;
        
    TreeNode *res = new TreeNode(0);
    TreeNode *node = res;
    res->right = node;
    
    stack<TreeNode*> st;
    st.push(A);
    
    while(!st.empty())
    {
        TreeNode *tmp = st.top();
        st.pop();
        
        node->right = tmp;
        node->left = NULL;
        
        node = node->right;
        
        if(tmp->right)
            st.push(tmp->right);
        if(tmp->left)
            st.push(tmp->left);
    }
    
    return res->right;
}


