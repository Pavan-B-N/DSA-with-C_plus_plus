// https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
/*
Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL

*/
#include <iostream>
#include <unordered_set>
#include "SinglyLinkedList.h"
using namespace std;

// hashing
void findMergeNode(Node* n1, Node* n2) {
    unordered_set<Node*> hashSet;
    while (n1 != NULL) {
        hashSet.insert(n1);
        n1 = n1->next;
    }
    while (n2) {
        if (hashSet.find(n2) != hashSet.end()) {
            cout << n2->data << endl;
            break;
        }
        n2 = n2->next;
    }
}


// approach 2 = using difference in node counts:
int getListLength(Node* head) {
	Node* current = head;
	int length = 0;
	while (current != nullptr) {
		length++;
		current = current->next;
	}
	return length;
}

int getIntersectionNodeValue(int difference, Node* head1, Node* head2) {
	Node* current1 = head1;
	Node* current2 = head2;
    // Move the pointer forward
	for (int i = 0; i < difference; i++) {
		if (current1 == nullptr) {
			return -1;
		}
		current1 = current1->next;
	}
    // Move both pointers of both list till they
    // intersect with each other
	while (current1 != nullptr && current2 != nullptr) {
		if (current1 == current2)
			return current1->data;
		current1 = current1->next;
		current2 = current2->next;
	}
	return -1;
}

int getIntersectionNodeValue(Node* head1, Node* head2) {
	int length1 = getListLength(head1);
	int length2 = getListLength(head2);
	int difference = abs(length1 - length2);

	if (length1 > length2) {
		return getIntersectionNodeValue(difference, head1, head2);
	}
	else {
		return getIntersectionNodeValue(difference, head2, head1);
	}
}


// two pointer metod
Node* findIntersection(Node* head1, Node* head2) {
	Node* ptr1 = head1;
	Node* ptr2 = head2;

	if (ptr1 == nullptr || ptr2 == nullptr)
		return nullptr;

	while (ptr1 != ptr2) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;

		if (ptr1 == ptr2)
			return ptr1;

		if (ptr1 == nullptr)
			ptr1 = head2;

		if (ptr2 == nullptr)
			ptr2 = head1;
	}
	return ptr1;
}