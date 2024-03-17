#include "DoublyLinkedList.h"

// Node Constructor
Node::Node(int value) : data(value), prev(nullptr), next(nullptr) {}

// Node Destructor
Node::~Node() {}

// Doubly Linked List Constructor
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Doubly Linked List Destructor
DoublyLinkedList::~DoublyLinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyLinkedList::insertAtFirst(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void DoublyLinkedList::removeAtFirst() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }
}

void DoublyLinkedList::removeAtEnd() {
    if (tail != nullptr) {
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }
}

void DoublyLinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "null" << std::endl;
}
