#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

class Node {
public:
    int data;
    Node* next;

    Node(int value);
};

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList();
    ~CircularLinkedList();

    void insertAtFirst(int value);
    void insertAtEnd(int value);
    void removeAtFirst();
    void removeAtEnd();
    void display();
};

#endif  // CircularLinkedList
