//  merge sort for ll
#include <iostream>
#include "SinglyLinkedList.h"

Node* getMiddle(Node* head) {
    if (!head || !head->next)
        return head;
    
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr; // Disconnect the list
    return mid;
}

Node* mergeLL(Node* left, Node* right) {
    Node* dummy = new Node(-1);
    Node* current = dummy;

    while (left && right) {
        if (left->data < right->data) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    current->next = left ? left : right;

    return dummy->next;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next)
        return head;

    Node* mid = getMiddle(head);
    Node* left = head;
    Node* right = mid;

    Node* leftSorted = mergeSort(left);
    Node* rightSorted = mergeSort(right);

    return mergeLL(leftSorted, rightSorted);
}

int main(){
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(2);
    list.insertAtEnd(5);
    list.insertAtEnd(40);
    list.display();

    list.head=mergeSort(list.head);
    list.display();
    return 0;
}