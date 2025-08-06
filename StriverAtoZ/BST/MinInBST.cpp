// https://www.naukri.com/code360/problems/minimum-element-in-bst_8160462?leftPanelTabValue=PROBLEM
#include "Node.h"
#include <climits>
#include <algorithm>
using namespace std;

int minVal(Node *root)
{
    int minEle = INT_MAX;
    while (root)
    {
        minEle = min(minEle, root->data);
        root = root->left;
    }
    return minEle == INT_MAX ? -1 : minEle;
}