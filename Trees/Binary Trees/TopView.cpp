/*
       1
    /     \
   2       3
  /  \    /   \
4    5  6      7

Top view will be: 4 2 1 3 7
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
struct Node
{
  int data;
  Node *left;
  Node *right;
};
vector<int> topView(Node *root)
{
  vector<int> res;
  if (root == nullptr)
  {
    return res;
  }

  // Map to store the first node at each horizontal distance.
  map<int, int> topNodeMap;

  // Queue to perform BFS, storing pairs of node and horizontal distance.
  // {Node,Horizontal distance}
  queue<pair<Node *, int>> q;
  q.push({root, 0});

  while (!q.empty())
  {
    auto front = q.front();
    q.pop();

    Node *node = front.first;
    int hd = front.second; // Horizontal distance of the node.

    // If horizontal distance is not already present in the map, add it.
    if (topNodeMap.find(hd) == topNodeMap.end())
    {
      topNodeMap[hd] = node->data;
    }

    // Push the left and right children of the current node into the queue.
    if (node->left)
    {
      q.push({node->left, hd - 1});
    }
    if (node->right)
    {
      q.push({node->right, hd + 1});
    }
  }

  // Extracting the values from the map and preparing the result.
  for (auto it : topNodeMap)
  {
    res.push_back(it.second);
  }

  return res;
}
