#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
//1st approach
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    stack<int> st;
    LinkedListNode<int> *temp = head;
    while(temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

//2nd approach
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *cur = NULL;
    while(head)
    {
        LinkedListNode<int> *next = head->next;
        head->next = cur;
        cur = head;
        head = next;
    }
    return cur;
}
