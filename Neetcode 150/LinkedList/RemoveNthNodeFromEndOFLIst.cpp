// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
#include "ListNode.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        // Move fast pointer n steps ahead
        while (fast && n > 0)
        {
            fast = fast->next;
            n--;
        }
        // If fast is null, it means we are deleting the head
        if (!fast)
        {
            return head->next;
        }
        // Move both pointers until fast reaches the end
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if (slow->next)
            slow->next = slow->next->next;

        return head;
    }
};