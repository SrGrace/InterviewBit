/*

https://www.interviewbit.com/problems/postorder-traversal/


Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3

return [3,2,1].

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
vector<int> Solution::postorderTraversal(TreeNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int > v;
    stack<TreeNode*> st1, st2;
    
    st1.push(A);
    
    while(!st1.empty())
    {
        TreeNode *tmp = st1.top();
        st1.pop();
        
        st2.push(tmp);
        
        if(tmp->left)
            st1.push(tmp->left);
        if(tmp->right)
            st1.push(tmp->right);
    }
    while(!st2.empty())
    {
        v.push_back(st2.top()->val);
        st2.pop();
    }
    
    return v;
}


