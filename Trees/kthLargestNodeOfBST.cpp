
/*


Write a function to find the kth largest node in a
binary search tree

If the node is not found, return NULL .

Examples:

       4                                  
      / \                              
     2   8     
        / \                     
       5  10 
find 2nd largest node ==> 8                 

*/





int height(treeNode *root)
{
    if(!root)
        return 0;
    
    return 1 + max(height(root->left), height(root->right));
}

treeNode* find_kth_largest(treeNode* root, int k) 
{
        
    if(root)
    {
        int rh = height(root->right);
        if(rh+1 == k)
            return root;
            
        else if(k < rh)
        {
            return find_kth_largest(root->right, k);
        }
        else
            return find_kth_largest(root->left, k-rh-1);
    }
    return NULL;
        
}




