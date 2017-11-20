/*

https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/


Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7

return

[
         [3],
         [20, 9],
         [15, 7]
]

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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int>> v;
    bool lftToRgt = 1;
    
    if(!A)
        return v;
    
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty())
    {
        int sz = q.size();
        vector<int> v1(sz);
        
        for(auto i=0; i<sz; i++)
        {
            TreeNode *tmp = q.front();
            q.pop();
            
            int idx = (lftToRgt) ? i : (sz - i - 1);
            
            v1[idx] = tmp->val;
            
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
        
        lftToRgt = !lftToRgt;
    
        v.push_back(v1);
    }
    
    return v;
}


