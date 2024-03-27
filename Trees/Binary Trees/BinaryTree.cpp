#include <iostream>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int value;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        deleteTree(root);
    }

    void populate() {
        cout << "Enter Root Node Value: ";
        int value;
        cin >> value;
        root = new Node(value);
        populate(root);
    }

    void display() {
        cout << "\n\t\tRight child is above and Left child is below\t\n\n";
        prettyDisplay(root, 0);
    }

private:
    void populate(Node* node) {
        cout << "Do you want to enter left of the node " << node->value << " (1 for yes, 0 for no): ";
        bool left;
        cin >> left;
        if (left) {
            cout << "Enter the value of left of " << node->value << ": ";
            int value;
            cin >> value;
            node->left = new Node(value);
            populate(node->left);
        }
        cout << "Do you want to enter right of the node " << node->value << " (1 for yes, 0 for no): ";
        bool right;
        cin >> right;
        if (right) {
            cout << "Enter the value of right of " << node->value << ": ";
            int value;
            cin >> value;
            node->right = new Node(value);
            populate(node->right);
        }
    }

    void prettyDisplay(Node* node, int level) {
        if (node == nullptr) {
            return;
        }
        prettyDisplay(node->right, level + 1);

        for (int i = 0; i < level; i++) {
            cout << "    ";
        }

        cout << "|------->" << node->value << endl;
        prettyDisplay(node->left, level + 1);
    }

    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};

int main() {
    BinaryTree BT;
    BT.populate();
    BT.display();
    return 0;
}
