#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }

        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->child != NULL)
            {
                // flatten the child nodes
                // the node pointing to next node
                Node *next = curr->next;
                // now find the child node tail
                curr->next = flatten(curr->child);
                // calling recursion because this could have childs as well so
                // recursion will go inside it and check for any childs and
                // flatten it and then it will come back
                curr->child->prev = curr;
                curr->child = nullptr;
                // find tail and attach to next
                while (curr->next != nullptr)
                {
                    curr = curr->next;
                }
                if (next)
                {
                    next->prev = curr;
                    curr->next = next;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};