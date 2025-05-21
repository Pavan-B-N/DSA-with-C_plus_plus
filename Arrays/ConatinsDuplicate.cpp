// find whether the given array contains duplicate or not
// for finding duplicates it takes o(n^2)
// so sort the array with o(nlogn) complexity and compare the adjacent elemnets so if u find both are equal return false , therefore total time complexity is o(nlogn)
#include <iostream>
#include <set> // takes logn time complexity for insertion as well as for deletion of an element
#include <unordered_set>
#include <vector>
using namespace std;

// https://leetcode.com/problems/contains-duplicate/

// Time complexity = o(nlogn)
// set time complexity for each operation is logn due to red black tree
bool containsDuplicate(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i]) != s.end())
        {
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}
// time complexity = o(n)
// space complexity = o(n)
// unordered_set time complexity is constant because of hashing
bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i]) != s.end())
        {
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}


int main()
{
    vector<int> arr = {1, 2, 3, 3, 1};
    containsDuplicate(arr);
    return 0;
}