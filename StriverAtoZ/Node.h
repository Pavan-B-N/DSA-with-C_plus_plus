#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    int val;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
        : data(val),val(val), left(nullptr), right(nullptr) {}
};

#endif // NODE_H