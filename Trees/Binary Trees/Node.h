#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
        : data(val), left(nullptr), right(nullptr) {}
};

#endif // NODE_H