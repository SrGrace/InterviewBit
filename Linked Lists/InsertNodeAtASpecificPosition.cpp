/*

Given a singly-linked list, implement a function to insert a node at a specific position and return the modified list's head.

Examples: 

Linkedlist: 1->2->3, Head = 1

insert_at_position(Head,4,2) ==> 1->4->2->3

*position=2 means 2nd node in the list

LinkedList: NULL
Data to be inserted: 4
Position: 2                                                    NULL

LinkedList: 1->2->3
Data to be inserted: 4
Position: 2                                                    1->4->2->3

LinkedList: 1->4->2->3
Data to be inserted: 9
Position: 1                                                    9->1->4->2->3

LinkedList: 9->1->4->2->3
Data to be inserted: 8
Position: 6                                                    9->1->4->2->3->8

*/



listNode
{
    int value;                 /* value of the node */
    listNode* next;     /* points to the next linked-list node */
};

listNode* insert_at_position( listNode* head, int data, int pos)
{
    listNode *tmp = new listNode;
    
    tmp->value = data;
    tmp->next = NULL;
    
    if(pos == 1)
    {
        tmp->next = head;
        head = tmp;
        return head;
    }
    
    listNode *tmp1 = head;
    for(int i=1; i<pos-1; i++)
        tmp1 = tmp1->next;
        
    tmp->next = tmp1->next;
    tmp1->next = tmp;
    
    return head;
}




