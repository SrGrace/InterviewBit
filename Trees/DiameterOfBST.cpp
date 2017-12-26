

O(n)  &  O(n)


int height(treeNode *root)
{
    if(!root)
        return 0;
        
    return 1 + max(height(root->left), height(root->right));
}

int diameter(treeNode* root)
{
    if(!root)
        return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    
    return max((1+ lh+ rh), max(ld, rd));

}



