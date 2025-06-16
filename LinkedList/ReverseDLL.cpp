#include <iostream>
using namespace std;
// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution
{
public:
    DLLNode *reverseDLL(DLLNode *head)
    {
        if (!head || head->next == NULL)
        {
            return head;
        }
        DLLNode *curr = head;
        DLLNode *temp = nullptr;

        while (curr != nullptr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        return temp->prev;
    }
};