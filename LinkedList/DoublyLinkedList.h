#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int value);

    // Destructor
    ~Node();
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList();

    // Destructor
    ~DoublyLinkedList();

    void insertAtFirst(int value);

    void insertAtEnd(int value);

    void removeAtFirst();

    void removeAtEnd();

    void display();
};

#endif /* DOUBLY_LINKED_LIST_H */
