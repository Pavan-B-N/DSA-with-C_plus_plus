// https://leetcode.com/problems/merge-k-sorted-lists/
#include <queue>
#include <vector>
#include "ListNode.h"
using namespace std;

// k = number of linked lists
// N = total number of nodes across all lists
// Time Complexity: O(N log k)
// O(k) extra space
class Solution
{
public:
    // Min-Heap approach — O(n log k)
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto comparator = [](const ListNode *a, const ListNode *b)
        {
            return a->val > b->val; // smaller value = higher priority
        };
        // decltype(comparator) → “type of comparator lambda”
        priority_queue<ListNode *, vector<ListNode *>, decltype(comparator)> pq;

        // pushing only heads
        for (auto node : lists)
        {
            if (node)
                pq.push(node);
        }

        ListNode *head = new ListNode(0);
        ListNode *tail = head;

        // Step 2: Extract min and push next node from that list
        while (!pq.empty())
        {
            ListNode *smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next)
            {
                pq.push(smallest->next);
            }
        }

        return head->next;
    }
};

class Solution
{
public:
    // Time Complexity: O(k·n) (where n is the total number of nodes and k is  the number of lists).
    // Min-Heap approach — O(n log k)
    //     merge first list → O(n1 + n2)
    // merge result with third → O(n1 + n2 + n3)
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            head = mergeList(head, lists[i]);
        }
        return head;
    }

    // Time Complexity: O(2n)
    ListNode *mergeList(ListNode *list1, ListNode *list2)
    {
        if (!list1 || !list2)
        {
            return list1 ? list1 : list2;
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
        tail->next = list1 ? list1 : list2;
        return head->next;
    }
};