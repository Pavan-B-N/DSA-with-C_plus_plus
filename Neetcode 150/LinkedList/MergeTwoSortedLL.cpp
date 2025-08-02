// https://leetcode.com/problems/merge-two-sorted-lists/
#include "ListNode.h"
// optimal
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr || list2 == nullptr)
        {
            return list1 == nullptr ? list2 : list1;
        }
        ListNode *head = new ListNode();// dummy node
        ListNode *tail = head;
        
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }
        if (list1)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }
        return head->next;
    }
};
// space complexity = O(n+m)
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode();
        ListNode *tail = head;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                tail->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if (list1)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }
        return head->next;
    }
};
