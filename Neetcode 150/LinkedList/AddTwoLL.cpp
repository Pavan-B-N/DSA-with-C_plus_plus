// https://leetcode.com/problems/add-two-numbers/
#include "ListNode.h"

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        int carry = 0;
        while (list1 || list2 || carry)
        {
            int x = list1 ? list1->val : 0;
            int y = list2 ? list2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if (list1)
            {
                list1 = list1->next;
            }
            if (list2)
            {
                list2 = list2->next;
            }
        }
        return head->next;
    }
};