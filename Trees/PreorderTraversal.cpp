/*

https://www.interviewbit.com/problems/preorder-traversal/


Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3

return [1,2,3].

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
vector<int> Solution::preorderTraversal(TreeNode* A) 
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
            v.push_back(A->val);
            st.push(A);
            
            A = A->left;
        }
        if(st.empty())
            break;
            
        A = st.top();
        st.pop();
        
        A = A->right;
    }
    
    return v;
}


