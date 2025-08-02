// https://leetcode.com/problems/intersection-of-two-linked-lists/description/
#include "ListNode.h"
#include <unordered_set>
using namespace std;
// using hashing
// Time complexity: O(2n)
// Space complexity: O(n)

// by comparing
// Time complexity: O(3n)
// Space complexity: O(1)

// by swaing pointers like cycle decetion technique
// Time complexity: O(n1+n2)
// Space complexity: O(1)
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while (temp1 || temp2)
        {
            if (temp1 == nullptr)
                temp1 = headB;
            if (temp2 == nullptr)
                temp2 = headA;
            if (temp1 == temp2)
            {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return nullptr;
    }
};

class Solution
{
public:
    // Time complexity: O(3n)
    // Space complexity: O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int n1 = getLen(headA); // O(n)
        int n2 = getLen(headB); // O(n)

        // move longer list to same position
        while (n1 != n2)
        {
            if (n1 > n2)
            {
                headA = headA->next;
                n1--;
            }
            else
            {
                headB = headB->next;
                n2--;
            }
        }

        // O(n)
        while (headA && headB)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
    int getLen(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            head = head->next;
            count++;
        }
        return count;
    }
};
class Solution
{
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> hashSet;
        while (headA)
        {
            hashSet.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (hashSet.find(headB) != hashSet.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};