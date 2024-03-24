/*
Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. (Not just immediate Right , but entire List on the Right)

input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
Explanation: All the nodes except the last
node has a greater value node on its right,
so all the nodes except the last node must
be removed.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/
#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

// o(n)
Node* deleteNodesOnRightSide(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    
    Node* nextNode = deleteNodesOnRightSide(head->next);
    
    if(nextNode->data > head->data) {
        return nextNode;
    }
    
    head->next = nextNode;
    
    return head;
}

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

// o(n^2)
Node* removeLesserElements(Node* head) {
    // If the list is empty or has only one node, return head
    if (head == nullptr || head->next == nullptr)
        return head;

    // Reverse the linked list
    head = reverseLinkedList(head);

    Node* maxNode = head;
    Node* temp = head->next;
    maxNode->next = nullptr; // The first node will always be part of the result

    while (temp != nullptr) {
        // If the current node's value is greater than or equal to maxNode's value,
        // add it to the result and update maxNode
        if (temp->data >= maxNode->data) {
            Node* newNode = temp;
            temp = temp->next;
            newNode->next = maxNode;
            maxNode = newNode;
        } else { // If the current node's value is less than maxNode's value, skip it
            Node* delNode = temp;
            temp = temp->next;
            delete delNode;
        }
    }

    // Reverse the result back to original order
    return reverseLinkedList(maxNode);
}


int main(int argc, char const *argv[])
{
    SinglyLinkedList list;
    // 12->15->10->11->5->6->2->3
    list.insertAtEnd(12);
    list.insertAtEnd(15);
    list.insertAtEnd(10);
    list.insertAtEnd(11);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    list.insertAtEnd(2);
    list.insertAtEnd(3);


    list.display();

    // list.head=deleteNodesOnRightSide(list.head);
    list.head=removeLesserElements(list.head);

    list.display();
    return 0;
}

