// https://leetcode.com/problems/copy-list-with-random-pointer/description/
#include "ListNode.h"
#include <unordered_map>
using namespace std;

class Solution
{
public:
    ListNode *copyRandomList(ListNode *head)
    {
        if (!head)
            return nullptr;

        // Step 1: Insert copied ListNodes
        // Interleave cloned ListNodes with original list
        ListNode *curr = head;
        while (curr)
        {
            ListNode *newListNode = new ListNode(curr->val);
            newListNode->next = curr->next;
            curr->next = newListNode;
            curr = newListNode->next;
        }

        // Step 2: Copy random pointers
        curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Separate original and copied list
        ListNode *copyHead = head->next;
        curr = head;

        while (curr)
        {
            ListNode *copy = curr->next;
            curr->next = copy->next; // Restore original list
            curr = curr->next;

            if (curr)
            {
                copy->next = curr->next;
            }
        }

        return copyHead;
    }
};

class Solution
{
public:
    ListNode *copyRandomList(ListNode *head)
    {
        if (!head)
        {
            return head;
        }

        unordered_map<ListNode *, ListNode *> hashMap;
        ListNode *temp = head;
        while (temp)
        {
            hashMap[temp] = new ListNode(temp->val);
            temp = temp->next;
        }

        //  for (auto [oldListNode, newListNode] : hashMap)
        // {
        //     if (oldListNode->next)
        //         newListNode->next = hashMap[oldListNode->next];
        //     if (oldListNode->random)
        //         newListNode->random = hashMap[oldListNode->random];
        // }
        for (auto it = hashMap.begin(); it != hashMap.end(); ++it)
        {
            ListNode *oldListNode = it->first;
            ListNode *newListNode = it->second;
            if (oldListNode->next)
                newListNode->next = hashMap[oldListNode->next];
            if (oldListNode->random)
                newListNode->random = hashMap[oldListNode->random];
        }
        return hashMap[head];
    }
};