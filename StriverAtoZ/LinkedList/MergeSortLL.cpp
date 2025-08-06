// https://leetcode.com/problems/sort-list/
#include "ListNode.h"
#include <queue>
using namespace std;
// brute force = minHeap
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

// optimal = inPlace MergeSortLL
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *mid = getMid(head);

        ListNode *leftSorted = sortList(head);
        ListNode *rightSorted = sortList(mid);

        return mergeLL(leftSorted, rightSorted);
    }
    ListNode *mergeLL(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr || list2 == nullptr)
        {
            return list1 != nullptr ? list1 : list2;
        }

        ListNode *head = new ListNode(0);
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
        if (list2)
        {
            tail->next = list2;
        }

        return head->next;
    }
    ListNode *getMid(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr; // Disconnect the list
        return mid;
    }
};

// brute force = minHeap
class Solution
{
public:
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // Min-heap to store (val, node) pairs
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> minHeap;

        // Insert all nodes into the heap
        ListNode *curr = head;
        while (curr)
        {
            minHeap.push({curr->val, curr});
            curr = curr->next;
        }

        // Start constructing the sorted list
        ListNode *newHead = minHeap.top().second;
        minHeap.pop();
        ListNode *tail = newHead;

        while (!minHeap.empty())
        {
            tail->next = minHeap.top().second;
            minHeap.pop();
            tail = tail->next;
        }

        tail->next = nullptr; // Terminate list properly

        return newHead;
    }
};
