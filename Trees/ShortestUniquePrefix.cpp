/*

https://www.interviewbit.com/problems/shortest-unique-prefix/


Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov

    NOTE : Assume that no word is prefix of another. In other words, the representation is always possible. 

*/



struct trie
{
    int freq;
    trie *child[26];
};

trie *getNode()
{
    trie *node = new trie();
    for(int i=0; i<26; i++)
        node->child[i] = NULL;
    
    node->freq = 1;
    
    return node;
}

void insert(trie *root, string s)
{
    trie *curr = root;
    for(auto i=0; i<s.size(); i++)
    {
        int idx = int(s[i]-'a');
        if(!curr->child[idx])
            curr->child[idx] = getNode();
        else
            (curr->child[idx]->freq)++;
        curr = curr->child[idx];
    }
}


string find_prefixUtil(trie *root, string pre)
{
    string s="";
    for(int i=0; i<pre.size(); i++)
    {
        int idx = int(pre[i]-'a');
        
        if(!root->child[idx])
            return s;
            
        if(root->child[idx]->freq == 1)
        {
            s += pre[i];
            return s;
        }
        else
        {
            s += pre[i];
            root = root->child[idx];
        }
    }
    return s;
}

vector<string> Solution::prefix(vector<string> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<string> v;
    string s;
    
    trie *root = getNode();
    root->freq = 0;
    
    for(int i=0; i<A.size(); i++)
        insert(root, A[i]);
        
    for(int i=0; i<A.size(); i++)
    {
        s = find_prefixUtil(root, A[i]);
        v.push_back(s);
    }
    
    return v;
    
}

