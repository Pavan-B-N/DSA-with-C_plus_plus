#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

Node* reverseDoublyLinkedList(Node* head) {
    Node* temp = nullptr;
    Node* current = head;
    
    // Swap next and prev pointers of each node
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node
    }
    
    // Update the head pointer
    if (temp != nullptr) {
        head = temp->prev;
    }
    
    return head;
}

int main(){
    DoublyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display();

    list.head=reverseDoublyLinkedList(list.head);
    list.display();
    return 0;
}