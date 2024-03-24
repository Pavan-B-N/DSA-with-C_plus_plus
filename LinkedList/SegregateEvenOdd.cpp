/*
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

Input: 
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

*/
#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

Node* segregateEvenOdd(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* evenHead = nullptr;
    Node* oddHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddTail = nullptr;

    while (head != nullptr) {
        if (head->data % 2 == 0) { // Even node
            if (evenHead == nullptr) {
                evenHead = evenTail = head;
            } else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        } else { // Odd node
            if (oddHead == nullptr) {
                oddHead = oddTail = head;
            } else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        head = head->next;
    }

    // Connect even and odd lists
    if (evenHead != nullptr) {
        evenTail->next = oddHead;
    }
    if (oddHead != nullptr) {
        oddTail->next = nullptr;
    }

    return (evenHead != nullptr) ? evenHead : oddHead;
}