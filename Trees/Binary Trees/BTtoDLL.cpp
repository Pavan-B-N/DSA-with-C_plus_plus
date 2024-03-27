/*
https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place

Input:
      1
    /  \
   3    2
Output:
3 1 2
2 1 3
Explanation: DLL would be 3<=>1<=>2

*/

#include <iostream>
using namespace std;

// A binary tree node has data, and left and right pointers
struct node
{
  int data;
  node *left;
  node *right;
};

void BinaryTree2DoubleLinkedList(node *root, node **head)
{
  if (root == NULL)
    return;

  // Static variable to maintain the previously visited node
  static node *prev = NULL;

  // Recursively convert left subtree
  BinaryTree2DoubleLinkedList(root->left, head);

  // Convert this node
  if (prev == NULL)
    *head = root;
  else
  {
    root->left = prev;
    prev->right = root;
  }
  prev = root;

  // Recursively convert right subtree
  BinaryTree2DoubleLinkedList(root->right, head);
}

// Helper function to allocate a new node with the given data
node *newNode(int data)
{
  node *new_node = new node;
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return new_node;
}

// Function to print nodes in a given doubly linked list
void printList(node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->right;
  }
}

// Driver code
int main()
{
  // Create the binary tree
  node *root = newNode(10);
  root->left = newNode(12);
  root->right = newNode(15);
  root->left->left = newNode(25);
  root->left->right = newNode(30);
  root->right->left = newNode(36);

  // Convert the binary tree to DLL
  node *head = NULL;
  BinaryTree2DoubleLinkedList(root, &head);

  // Print the converted list
  printList(head);

  return 0;
}
