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

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr; // Early return for empty list

        unordered_map<Node *, Node *> map; // Mapping from original nodes to copied nodes

        // Step 1: Create a copy of each node and store in the map
        Node *originalNode = head;
        Node *copiedHead = new Node(-1); // Temporary head for the new list
        Node *copiedNode = copiedHead;

        while (originalNode != nullptr)
        {
            Node *newNode = new Node(originalNode->val);
            copiedNode->next = newNode;
            copiedNode = newNode;
            map[originalNode] = newNode; // Store the mapping of original node to copied node
            originalNode = originalNode->next;
        }

        copiedHead = copiedHead->next; // Move to the actual head of the new list

        // Step 2: Set the random pointers for the copied nodes
        originalNode = head;
        copiedNode = copiedHead;

        while (originalNode != nullptr)
        {
            if (originalNode->random)
            {
                copiedNode->random = map[originalNode->random]; // Map random pointer
            }
            originalNode = originalNode->next;
            copiedNode = copiedNode->next;
        }

        return copiedHead;
    }
};
