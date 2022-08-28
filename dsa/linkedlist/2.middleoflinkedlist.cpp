// finding middle of the linked list efficient approach

Node *findMiddle(Node *head) {
    if(head==NULL)
    {
        return NULL;
    }
    Node *temp = head;
    Node *follow = head;
    while(temp!=NULL && temp->next!=NULL)
    {
        temp = temp->next->next;
        follow = follow->next;
    }
    return follow;
}

//brute force approach is finding length of linked list and then iterating till its middle.
