
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





int tree_size(treeNode *root)
{
    if(!root)
        return 0;
    
    return tree_size(root->left) + 1 + tree_size(root->right);
}

treeNode* find_kth_largest(treeNode* root, int k) 
{
        
    if(!root)
        return NULL;
    
    int rh = 0;
    if(root->right)
        rh  = tree_size(root->right);
       
    if(rh+1 == k)
        return root;

    else if(k < rh)
        return find_kth_largest(root->right, k);
    
    else
        return find_kth_largest(root->left, k-rh-1);
  
}




