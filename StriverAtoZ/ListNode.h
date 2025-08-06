#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode
{
public:
    int data;
    int val;
    ListNode *random;
    ListNode *bottom;
    ListNode *next;
    ListNode *prev;

    // Constructor to initialize a new node
    ListNode(int val)
        : data(val), next(nullptr), prev(nullptr), random(nullptr), bottom(nullptr) {}
};

#endif // LISTNODE_H