// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
#include "ListNode.h"

class Solution
{
public:
    ListNode *reverseDLL(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *curr = head;
        ListNode *temp = nullptr;

        while (curr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        return temp->prev;
    }
};