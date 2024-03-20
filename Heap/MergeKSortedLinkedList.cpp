// v.v.v.imp
// refer the linked list part
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Custom comparator for Node pointers
struct NodeComparator {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->val > rhs->val; // Min heap comparison
    }
};

// Function to merge k sorted linked lists using min heap
Node* mergeKLists(vector<Node*>& lists) {
    // Define min heap for Node pointers
    priority_queue<Node*, vector<Node*>, NodeComparator> minHeap;

    // Push the head nodes of all lists into the min heap
    for (Node* head : lists) {
        if (head) {
            minHeap.push(head);
        }
    }

    // Dummy node to simplify code
    Node* dummy = new Node(0);
    Node* tail = dummy;

    // Merge lists
    while (!minHeap.empty()) {
        Node* minNode = minHeap.top();
        minHeap.pop();
        tail->next = minNode;
        tail = tail->next;

        if (minNode->next) {
            minHeap.push(minNode->next);
        }
    }

    return dummy->next;
}

// Utility function to print the elements of a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create linked lists
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(6);

    Node* head2 = new Node(1);
    head2->next = new Node(5);

    Node* head3 = new Node(1);
    head3->next = new Node(1);
    head3->next->next = new Node(3);
    head3->next->next->next = new Node(7);

    Node* head4 = new Node(8);

    // Merge lists
    vector<Node*> lists = {head1, head2, head3, head4};
    Node* mergedList = mergeKLists(lists);

    // Print the merged list
    cout << "Merged list: ";
    printList(mergedList);

    return 0;
}
