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
                Node *next = curr->next;
                Node *newHead= flatten(curr->child);
                curr->next=newHead;
                newHead->prev = curr;
                curr->child = NULL;

                // find tail
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }

                // attach tail with next ptr
                if (next != NULL)
                {
                    //tail->next
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};