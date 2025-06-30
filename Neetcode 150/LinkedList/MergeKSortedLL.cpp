// https://leetcode.com/problems/merge-k-sorted-lists/
#include "ListNode.h"
#include <vector>
using namespace std;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            head = mergeList(head, lists[i]);
        }
        return head;
    }

    ListNode *mergeList(ListNode *list1, ListNode *list2)
    {
        if (!list1 || !list2)
        {
            return list1 ? list1 : list2;
        }
        ListNode *head;
        if (list1->val < list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }

        ListNode *tail = head;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
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
        return head;
    }
};