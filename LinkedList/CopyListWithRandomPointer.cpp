// https://leetcode.com/problems/copy-list-with-random-pointer/description/
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// optimal
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        // Step 1: Insert copied nodes
        // Interleave cloned nodes with original list
        Node *curr = head;
        while (curr)
        {
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
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
        Node *copyHead = head->next;
        curr = head;

        while (curr)
        {
            Node *copy = curr->next;
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
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return head;
        }

        unordered_map<Node *, Node *> hashMap;
        Node *temp = head;
        while (temp)
        {
            hashMap[temp] = new Node(temp->val);
            temp = temp->next;
        }

        //  for (auto [oldNode, newNode] : hashMap)
        // {
        //     if (oldNode->next)
        //         newNode->next = hashMap[oldNode->next];
        //     if (oldNode->random)
        //         newNode->random = hashMap[oldNode->random];
        // }
        for (auto it = hashMap.begin(); it != hashMap.end(); ++it)
        {
            Node *oldNode = it->first;
            Node *newNode = it->second;
            if (oldNode->next)
                newNode->next = hashMap[oldNode->next];
            if (oldNode->random)
                newNode->random = hashMap[oldNode->random];
        }
        return hashMap[head];
    }
};