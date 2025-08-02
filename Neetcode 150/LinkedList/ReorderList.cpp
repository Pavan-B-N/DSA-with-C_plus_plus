// https://leetcode.com/problems/reorder-list
/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/
#include "ListNode.h"
#include <deque>
using namespace std;
// optimal , O(1)
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        // find the middle of list
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse ll
        ListNode *head2 = reverse(slow->next);
        slow->next = nullptr; // split the list

        // now we can reorder
        // head,head2
        while (head2)
        {
            ListNode *temp1 = head->next;
            ListNode *temp2 = head2->next;
            head->next = head2;
            head2->next = temp1;
            head = temp1;
            head2 = temp2;
        }
    }
    ListNode *reverse(ListNode *head)
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
// using deque
// space complexity = o(n)
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        deque<ListNode *> dq;
        ListNode *tail = head;
        while (tail != nullptr)
        {
            dq.push_back(tail);
            tail = tail->next;
        }

        tail = nullptr; // reset tail for building the new list
        while (!dq.empty())
        {
            if (dq.size() >= 2)
            {
                ListNode *first = dq.front();
                dq.pop_front();
                ListNode *last = dq.back();
                dq.pop_back();

                if (tail != nullptr)
                    tail->next = first;
                first->next = last;
                tail = last;
            }
            else
            {
                if (tail != nullptr)
                    tail->next = dq.front();
                tail = dq.front();
                dq.pop_front();
            }
        }

        // Ensure the final node points to null
        tail->next = nullptr;
    }
};
