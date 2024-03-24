#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

Node* rotateDoublyLinkedList(Node* head, int N) {
    if (head == nullptr || N == 0)
        return head;

    Node* current = head;

    // Traverse to the Nth node
    int count = 1;
    while (count < N && current != nullptr) {
        current = current->next;
        count++;
    }

    // If current is nullptr, then N is greater than the length of the list
    if (current == nullptr)
        return head;

    // current points to the Nth node
    Node* NthNode = current;

    // Traverse to the end of the list
    while (current->next != nullptr)
        current = current->next;

    // Connect the last node to the head
    current->next = head;
    head->prev = current;

    // Update head to the (N+1)th node and break the link
    head = NthNode->next;
    head->prev = nullptr;
    NthNode->next = nullptr;

    return head;
}