/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

Input:      5 -> 10 -> 19 -> 28
            |     |      |     |
            V     V      V     V
            7     20     22    35
            |             |     |
            V             V      V
            8             50     40
            |                     |
            V                     V
           30                     45
*/
#include <iostream>
#include <queue>
using namespace std;

// Linked list Node
struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// comparator function for priority queue
struct mycomp {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};
// we have 'N' elements in the linked list and each element is inserted into the priority queue once, the time complexity for this part is O(N * log N).
void flatten(Node* root) {
    priority_queue<Node*, vector<Node*>, mycomp> p;
    // pushing main link nodes into priority_queue.
    while (root != NULL) {
        p.push(root);
        root = root->next;
    }

    // Extracting the minimum node
    // while priority queue is not empty
    while (!p.empty()) {
        // extracting min
        auto k = p.top();
        p.pop();

        // printing least element
        cout << k->data << " ";
        if (k->bottom)
            p.push(k->bottom);
    }
}

int main() {
    Node* head = new Node(5);
    auto temp = head;
    auto bt = head;
    bt->bottom = new Node(7);
    bt->bottom->bottom = new Node(8);
    bt->bottom->bottom->bottom = new Node(30);
    temp->next = new Node(10);

    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(20);
    temp->next = new Node(19);
    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(22);
    bt->bottom->bottom = new Node(50);
    temp->next = new Node(28);
    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(35);
    bt->bottom->bottom = new Node(40);
    bt->bottom->bottom->bottom = new Node(45);

    // Function call
    flatten(head);
    cout << endl;

    // Deallocate memory
    while (head != nullptr) {
        auto nextNode = head->next;
        delete head;
        head = nextNode;
    }

    return 0;
}
