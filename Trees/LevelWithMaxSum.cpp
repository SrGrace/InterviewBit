

int level_with_max_sum(treeNode *root)
{
    if(!root)
        return -1;
      
    std::queue<treeNode*>q ;
    q.push(root);
    q.push(NULL);
    
    int sum = 0, max_sum = 0, level = 0, max_level = 0;    
    while(!q.empty())
    {
        treeNode *tmp = q.front();
        q.pop();
        
        if(!tmp)
        {
            if(sum > max_sum)
            {
                max_sum  = sum;
                max_level = level;
            }
            sum = 0;
    
            if(!q.empty())
                q.push(NULL);
            level++;
        }
        else
        {
            sum += tmp->value;
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
    }
    return max_level;

}




