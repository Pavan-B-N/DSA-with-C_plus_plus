// https://leetcode.com/problems/reverse-nodes-in-k-group/
#include "ListNode.h"

// practice both
// recursive approach
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        int count = 0;
        while (count < k)
        {
            if (temp == nullptr)
            {
                // we don't have enough nodes to reverse
                return head;
            }
            temp = temp->next;
            count++;
        }

        // recursively call for rest of LL
        ListNode *prevNode = reverseKGroup(temp, k);

        // reverse the current group
        ListNode *curr = head;
        ListNode *next = curr->next;
        count = 0;
        while (count < k)
        {
            curr->next = prevNode;
            prevNode = curr;
            curr = next;
            if (next)
            {
                next = next->next;
            }
            count++;
        }
        return prevNode;
    }
};

// iterative approach
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        ListNode *next = nullptr;

        while (head)
        {
            ListNode *startNode = head;
            int count = 1;
            while (count < k && head)
            {
                head = head->next;
                count++;
            }

            // Not enough nodes to reverse
            if (!head)
            {
                tail->next = startNode;
                break;
            }

            next = head->next;    // Save the start of the next group
            head->next = nullptr; // Cut the current group

            // Reverse and connect
            ListNode *newHead = reverseList(startNode);
            tail->next = newHead;

            // Move tail to the end of the reversed group
            while (tail->next)
                tail = tail->next;

            // Move to next group
            head = next;
        }

        return dummy->next;
    }

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