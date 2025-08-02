// https://leetcode.com/problems/odd-even-linked-list/
#include "ListNode.h"

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // The first node is considered odd, and the second node is even,
        // 1 based indexing
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even; // store head of even list

        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead; // attach even list at the end of odd list

        return head;
    }
};
