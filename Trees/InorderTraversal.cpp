/*

https://www.interviewbit.com/problems/inorder-traversal/


Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3

return [1,3,2].

Using recursion is not allowed.

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
vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> v;  
    stack<TreeNode*> st;
    
    while(true)
    {
        while(A)
        {
            st.push(A);
            A = A->left;
        }
        if(st.empty())
            break;
            
        A = st.top();
        v.push_back(A->val);
        st.pop();
        
        A = A->right;
    }
    
    return v;
}



