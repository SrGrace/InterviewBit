/*

https://www.interviewbit.com/problems/unique-binary-search-trees/
https://leetcode.com/problems/unique-binary-search-trees-ii/description/


Given A, generate all structurally unique BST’s (binary search trees) that store values 1...A.

Example : 
Given A = 3, your program should return all 5 unique BST’s shown below.


   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
*/
 
 
 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<TreeNode*> generate(int st, int ed)
    {
        vector<TreeNode*> v;

        if(st > ed)
        {
            v.push_back(NULL);
            return v;
        }

        if(st == ed)
        {
            v.push_back(new TreeNode(st));
            return v;
        }

        for(auto i=st; i<=ed; i++)
        {
            vector<TreeNode *> lft = generate(st, i-1);
            vector<TreeNode *> rgt = generate(i+1, ed);

            for(auto l : lft)
            {
                for(auto r : rgt)
                {
                    TreeNode *root = new TreeNode(i);

                    root->left = l;
                    root->right = r;

                    v.push_back(root);
                }
            }
        }
        return v;
    }

    vector<TreeNode*> generateTrees(int n)
    {
        
        if(n == 0)
            return vector<TreeNode*>();
        else 
            return generate(1, n);
    }
};



