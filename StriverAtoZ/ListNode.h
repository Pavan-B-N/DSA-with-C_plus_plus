#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode
{
public:
    int data;
    int val;
    ListNode *next;
    ListNode *prev;

    // Constructor to initialize a new node
    ListNode(int val)
        : data(val), next(nullptr), prev(nullptr) {}
};

#endif // LISTNODE_H