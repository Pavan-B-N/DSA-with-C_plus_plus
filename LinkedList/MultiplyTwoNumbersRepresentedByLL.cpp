/*
Given two numbers represented by linked lists, write a function that returns the multiplication of these two linked lists.

Input : 9->4->6
        8->4
Output : 79464
*/
#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;
// Time Complexity: O(max(n1, n2)), where n1 and n2 represents the number of nodes present in the first and second linked list respectively.
long multiplyTwoLists(Node* first, Node* second) {
    long long num1 = 0, num2 = 0;

    while (first || second) {
        if (first) {
            num1 = ((num1) * 10) + first->data;
            first = first->next;
        }

        if (second) {
            num2 = ((num2) * 10) + second->data;
            second = second->next;
        }
    }

    return num1 * num2;
}

int main() {
    SinglyLinkedList num1List;
    num1List.insertAtEnd(9);
    num1List.insertAtEnd(4);
    num1List.insertAtEnd(6);

    SinglyLinkedList num2List;
    num2List.insertAtEnd(8);
    num2List.insertAtEnd(4);

    cout << "First Number: ";
    num1List.display();
    cout << "Second Number: ";
    num2List.display();

    long long result = multiplyTwoLists(num1List.head, num2List.head);

    cout << "Multiplication Result: " << result << endl;

    return 0;
}
