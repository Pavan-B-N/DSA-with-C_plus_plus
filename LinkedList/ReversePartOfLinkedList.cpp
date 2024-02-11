/*
reverse part of the linked list
// 10 -> 20 -> 30 -> 40 -> 50 -> 60
// 40 -> 30 -> 20 -> 10 -> 50 -> 60 -> null with start=0 and end=3

*/
#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

Node *getNode(Node *head, int index)
{
    Node *temp = head; // 0th index
    while (index > 0 && temp->next != nullptr)
    {
        temp = temp->next;
        index--;
    }
    return temp;
}
void inPlaceReversalSubList(Node *first, Node *last)
{
    if (first == nullptr || first->next == nullptr)
    {
        return;
    }
    Node *previous = nullptr;
    Node *current = first;
    Node *next = first->next;

    while (previous != last)
    {
        current->next = previous;
        previous = current;
        current = next;
        if (next != nullptr)
        {
            next = next->next;
        }
    }
}

Node *reversePartOfLinkedList(Node *head, int start, int end)
{
    Node *first = getNode(head, start);
    Node *last = getNode(head, end);
    
    // case 1 strat=0 end=5
    // case 2 strat=0 end=3
    // case 3 strat=3 end=5
    // case 4 strat=1 end=4

    if (first == head && last->next == nullptr)
    {
        inPlaceReversalSubList(first, last);
        return last; // head
    }
    else if (first == head && last->next != nullptr)
    {
        Node *after = getNode(head, end + 1);
        inPlaceReversalSubList(first, last);
        first->next = after;
        return last;
    }
    else if (last->next == nullptr)
    {
        Node *before = getNode(head, start - 1);
        inPlaceReversalSubList(first, last);
        before->next = last;
    }
    else
    {
        // both are in between
        Node *before = getNode(head, start - 1);
        Node *after = getNode(head, end + 1);
        cout << before->data << " " << after->data << endl;
        inPlaceReversalSubList(first, last);
        before->next = last;
        first->next = after;
    }
    return head;
}

int main()
{
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtEnd(60);
    // 10 -> 20 -> 30 -> 40 -> 50 -> 60
    int start = 0;
    int end = 3;
    list.head = reversePartOfLinkedList(list.head, start, end);
    // 40 -> 30 -> 20 -> 10 -> 50 -> 60 -> null with start=0 and end=3
    list.display();
    return 0;
}