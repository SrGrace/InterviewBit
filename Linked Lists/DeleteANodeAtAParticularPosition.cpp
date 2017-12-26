/*

Given a singly-linked list, implement a function to delete the node at a given position (starting from 1 as the head position) and return the head of the list. Do nothing if the input position is out of range.

Examples:

LinkedList: 1->2->3->4, Head = 1

delete_at_pos(Head,3) ==> 1->2->4

*/


# 1st method (non-recursive)


listNode
{
    int value;                 /* value of the node */
    listNode* next;     /* points to the next linked-list node */
};

listNode* delete_at_pos(listNode* head, int n)
{
    if(!head)
        return NULL;
        
    if(n <= 0)
        return head;
        
    listNode *p = head, *q;
    int k = 1;
    
    if(n == 1)
    {
        head = head->next;
        delete(p);
        return head;
    }
    else
    {
        while(p && k<n)
        {
            k++;
            q = p;
            p = p->next;
        }
        if(!p)
           return head;
        else
        {
            q->next = p->next;
            delete(p);
        }
    }
    return head;
    
 }
 
 
 
# 2nd method (Recursive)
 
 
listNode* delete_at_pos(listNode* head, int n)
{ 
    if (n <= 0 || head == NULL)
    {
        return head;
    }
    
    if (n == 1) 
    {
        return head->next;
    }
    
    head->next = delete_at_pos(head->next, n - 1);
    
    return head;

}
  
  
  
  
  
  
