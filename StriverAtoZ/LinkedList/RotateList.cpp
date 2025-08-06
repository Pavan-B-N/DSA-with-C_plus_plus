// https://leetcode.com/problems/rotate-list/description/
#include "ListNode.h"

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
        {
            return head;
        }

        // find length
        ListNode *curr = head;
        int len = 1;
        while (curr->next)
        {
            curr = curr->next;
            len++;
        }

        k = k % len;
        if (k == 0)
            return head;

        // Make it circular
        curr->next = head;

        curr = head;
        for (int i = 1; i < len - k; i++)
        {
            curr = curr->next;
        }

        // Break the cycle and return new head
        ListNode *newHead = curr->next;
        curr->next = nullptr;

        return newHead;
    }
};