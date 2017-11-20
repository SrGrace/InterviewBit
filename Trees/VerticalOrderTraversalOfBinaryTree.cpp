/*

https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/


Given a binary tree, print a vertical order traversal of it.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9

returns

[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]

Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.

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

/*
void vertical(TreeNode *A, int hd, map<int, vector<int>> &mp)
{
    if(!A)
        return;
    
    mp[hd].push_back(A->val);
    
    vertical(A->left, hd-1, mp);
    
    vertical(A->right, hd+1, mp);
}
*/


vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A)
{
    map<int, vector<int>> mp;
    
    int hd = 0;
    //vertical(A, hd, mp);
    
    vector<vector<int>> v;
    
    if (!A)
        return vector<vector<int>>();

    queue<pair<TreeNode*, int> > que;
    que.push(make_pair(A, hd));
 
    while (!que.empty())
    {
        pair<TreeNode *,int> temp = que.front();
        que.pop();
        hd = temp.second;
        TreeNode* node = temp.first;
 
        mp[hd].push_back(node->val);
 
        if (node->left)
            que.push(make_pair(node->left, hd-1));
        if (node->right)
            que.push(make_pair(node->right, hd+1));
    }
 
    for(auto it : mp)
    {
        v.push_back(it.second);
    }

    return v;
}



