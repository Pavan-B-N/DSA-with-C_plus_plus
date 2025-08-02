// https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1
#include "ListNode.h"

class Solution
{
public:
    ListNode *insertAtEnd(ListNode *head, int x)
    {
        if (!head)
        {
            return new ListNode(x);
        }
        ListNode *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = new ListNode(x);
        return head;
    }
};