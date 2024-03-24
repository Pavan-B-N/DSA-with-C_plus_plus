/*
Input: 1 -> 1 -> 2 -> 0 -> 2 -> 0 -> 1 -> NULL 
Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2 -> NULL
*/
#include <iostream>
using namespace std;

// Linked list Node
struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

// sort a linked list of 0s, 1s, and 2s using frequency counting:
Node* sortLinkedList(Node* head) {
    int count[3] = {0}; // Count occurrences of 0, 1, and 2

    // Count occurrences of each element
    Node* current = head;
    while (current != nullptr) {
        count[current->data]++;
        current = current->next;
    }

    // Reconstruct the linked list with the correct number of each element
    current = head;
    int i = 0;
    while (current != nullptr) {
        if (count[i] == 0) {
            ++i;
        } else {
            current->data = i;
            --count[i];
            current = current->next;
        }
    }
    return head;
}

// Utility function to insert a node at the beginning of the linked list
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    Node* head = nullptr;
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 0);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 0);

    cout << "Original List: ";
    printList(head);

    head = sortLinkedList(head);

    cout << "Sorted List: ";
    printList(head);

    // Free allocated memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
