// https://leetcode.com/problems/reverse-linked-list/description/
#include "ListNode.h"

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = head->next;
        while (curr != nullptr)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next)
            {
                next = next->next;
            }
        }
        return prev;
    }
};