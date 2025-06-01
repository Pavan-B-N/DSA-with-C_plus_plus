
/*
Geek wants to know the traversals required to construct a unique binary tree. Given a pair of traversal, return true if it is possible to construct unique binary tree from the given traversals otherwise return false.

Each traversal is represented with an integer: 
preorder - 1, inorder - 2, postorder - 3. 
*/
// We cannot construct unique binary tree using preorder traversal and postorder traversal.
// We can only construct a unique binary tree with one of the given traversal is inorder only
// i.e inorder + preorder or inorder+postorder
// Preorder + Postorder	❌ = Multiple trees can match the same traversals

// https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1
class Solution {
  public:
    bool isPossible(int a, int b) {
        // 2 = inorder
        if(a==2 || b==2 ){
            return a!=b;// with inorder we need prorder or postorder
        }
        return false;
    }
};