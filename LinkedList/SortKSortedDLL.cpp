/*
Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list.


Solutions:
1.Naive Approach
2.Min Heap
*/

// refer heap

#include <iostream>
#include <queue>
#include "DoublyLinkedList.h"

using namespace std;

struct compare {
    bool operator()(Node* p1, Node* p2) {
        return p1->data > p2->data;
    }
};

// Function to sort a k sorted doubly linked list
Node* sortAKSortedDLL(Node* head, int k) {
    if (head == nullptr)
        return nullptr;

    priority_queue<Node*, vector<Node*>, compare> pq;

    Node* dummy = new Node(0); // Creating a dummy node
    Node* tail = dummy;
    Node* current = head;

    // Create a Min Heap of first (k+1) elements
    for (int i = 0; current != nullptr && i <= k; i++) {
        pq.push(current);
        current = current->next;
    }

    while (!pq.empty()) {
        tail->next = pq.top();
        pq.top()->prev = tail;
        tail = pq.top();
        pq.pop();

        if (current != nullptr) {
            pq.push(current);
            current = current->next;
        }
    }
    tail->next = nullptr;

    return dummy->next;
}

int main() {
    DoublyLinkedList dll;

    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    dll.insertAtEnd(8);
    dll.insertAtEnd(56);
    dll.insertAtEnd(12);
    dll.insertAtEnd(2);
    dll.insertAtEnd(6);
    dll.insertAtEnd(3);

    int k = 2;

    cout << "Original Doubly linked list:\n";
    dll.display();

    // Sort the k sorted DLL and get the new head
    dll.head=sortAKSortedDLL(dll.head,k);
    dll.display();

    return 0;
}

