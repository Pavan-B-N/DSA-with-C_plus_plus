#include <iostream>
#include <queue>
using namespace std;

class DoublyLinkedList
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node *dummyHead;

public:
    DoublyLinkedList()
    {
        dummyHead = new Node(0); // Dummy node creation
    }

    // Function to insert a node at the beginning of the Doubly Linked List
    void push(int newData)
    {
        Node *newNode = new Node(newData);
        newNode->next = dummyHead->next;
        if (dummyHead->next != nullptr)
            dummyHead->next->prev = newNode;
        dummyHead->next = newNode;
        newNode->prev = dummyHead;
    }

    // Function to print nodes in a given doubly linked list
    void printList()
    {
        Node *current = dummyHead->next;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
    struct compare
    {
        bool operator()(struct Node *p1, struct Node *p2)
        {
            return p1->data > p2->data;
        }
    };
    
    // Function to sort a k sorted doubly linked list
    void sortAKSortedDLL(int k)
    {
        if (dummyHead->next == nullptr)
            return;

        priority_queue<Node *, vector<Node *>, compare> pq;

        Node *tail = dummyHead;
        Node *head = dummyHead->next;

        // Create a Min Heap of first (k+1) elements
        for (int i = 0; head != nullptr && i <= k; i++)
        {
            pq.push(head);
            head = head->next;
        }

        while (!pq.empty())
        {
            tail->next = pq.top();
            pq.top()->prev = tail;
            tail = pq.top();
            pq.pop();

            if (head != nullptr)
            {
                pq.push(head);
                head = head->next;
            }
        }
        tail->next = nullptr;
    }
};

int main()
{
    DoublyLinkedList dll;

    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    dll.push(8);
    dll.push(56);
    dll.push(12);
    dll.push(2);
    dll.push(6);
    dll.push(3);

    int k = 2;

    cout << "Original Doubly linked list:\n";
    dll.printList();

    // Sort the k sorted DLL
    dll.sortAKSortedDLL(k);

    cout << "\nDoubly Linked List after sorting:\n";
    dll.printList();

    return 0;
}
