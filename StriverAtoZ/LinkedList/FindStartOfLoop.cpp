// https://leetcode.com/problems/linked-list-cycle-ii/
#include "ListNode.h"

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            // loop detected
            if (slow == fast)
            {
                fast = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast; // slow->next;
            }
        }
        return nullptr;
    }
};