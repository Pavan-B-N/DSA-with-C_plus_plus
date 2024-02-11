#include "CircularLinkedList.h"
#include <iostream>

// Node Class Implementation
Node::Node(int value) : data(value), next(nullptr) {}

// CircularLinkedList Class Implementation
CircularLinkedList::CircularLinkedList() : head(nullptr) {}

CircularLinkedList::~CircularLinkedList() {
    if (head == nullptr) return;

    Node* current = head->next;
    while (current != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
}

void CircularLinkedList::insertAtFirst(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
    } else {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void CircularLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->next = head;
}

void CircularLinkedList::removeAtFirst() {
    if (head != nullptr) {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        if (head == tail) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }
}

void CircularLinkedList::removeAtEnd() {
    if (head == nullptr) {
        return;
    }
    Node* tail = head;
    Node* secondTail = nullptr;
    while (tail->next != head) {
        secondTail = tail;
        tail = tail->next;
    }

    if (secondTail == nullptr) {
        delete head;
        head = nullptr;
    } else {
        secondTail->next = head;
        delete tail;
    }
}

void CircularLinkedList::display() {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    std::cout << temp->data << " -> " << head->data << "(head)" << std::endl;
}
