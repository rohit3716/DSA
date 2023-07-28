#include <bits/stdc++.h> 
#include <bits/stdc++.h> 


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


void reverse(LinkedListNode<int>* &head, LinkedListNode<int>* &prev, LinkedListNode<int>* curr) {
    // if(head == NULL || head -> next == NULL ) {
    //     return head;
    // }

    LinkedListNode<int>* forward = NULL;

    while( curr != NULL ) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    reverse(head,prev,curr);
    return prev;
}