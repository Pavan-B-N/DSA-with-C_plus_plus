// https://leetcode.com/problems/reverse-nodes-in-k-group/
#include "ListNode.h"
#include <iostream>
using namespace std;

// optimal
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prevLast = NULL;

        while (temp != NULL)
        {
            ListNode *kThNode = getKthNode(temp, k);
            if (kThNode == NULL)
            {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }

            ListNode *nextNode = kThNode->next;
            kThNode->next = NULL;

            // Reverse current k-group
            reverseLinkedList(temp);

            // Connect reversed part
            if (temp == head)
            {
                head = kThNode;
            }
            else
            {
                prevLast->next = kThNode;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }

    // Helper to reverse a linked list
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *prev = NULL;
        while (head)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    // Helper to get k-th node from current node
    ListNode *getKthNode(ListNode *temp, int k)
    {
        k = k - 1;
        while (temp != NULL && k > 0)
        {
            temp = temp->next;
            k--;
        }
        return temp;
    }
};

// Extra space due to stack
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