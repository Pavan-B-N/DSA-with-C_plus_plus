// SinglyLinkedList.h
#pragma once

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {};
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList();
    ~SinglyLinkedList();
    void insertAtFirst(int value);
    void insertAtEnd(int value);
    void removeAtFirst();
    void removeAtEnd();
    void display();
};
