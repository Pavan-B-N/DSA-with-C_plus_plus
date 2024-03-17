#include <iostream>
#include <vector>
#include <set> // implemented using balanced bst so o(logn), sorted order, Ordered collection, Deterministic iteration order
#include <unordered_set> // implemented using hashtable so o(1), random order
using namespace std;

vector<int> union_arr(vector<int> arr1, vector<int> arr2)
{
    set<int> hashSet;
    hashSet.insert(arr1.begin(), arr1.end());
    hashSet.insert(arr2.begin(), arr2.end());

    // copy set to a vector
    vector<int> res(hashSet.begin(), hashSet.end());
    return res;
}

vector<int> intersection_arr(vector<int> arr1, vector<int> arr2)
{
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> set2(arr2.begin(), arr2.end());

    vector<int> res;
    for (auto &ele : set1)
    {
        if (set2.find(ele) != set2.end())
        {
            res.push_back(ele);
        }
    }
    return res;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 6};

    return 0;
}