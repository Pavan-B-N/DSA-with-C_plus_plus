// https://www.geeksforgeeks.org/problems/smaller-on-left20360700/1
#include <vector>
#include <set>
#include <iostream>
using namespace std;

// nlogn
vector<int> Smallestonleft(int arr[], int n)
{
    vector<int> res(n, -1);
    set<int> seen;

    for (int i = 0; i < n; i++)
    {
        // set.lower_bound(val) gives the ceiling of val in the set.
        auto it = seen.lower_bound(arr[i]);// loweBound >= arr[i]
        if (it != seen.begin())
        {
            --it;
            res[i] = *it;
        }
        seen.insert(arr[i]);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    set<int> s = {2, 4, 6, 8, 10};
    // Returns an iterator pointing to the first element in the set which is not less than (>=) the given value val.
    // It finds the smallest element in the set that is ≥ val
    // {2, 4, 6, 8, 10};
    // Lower bound of 5 is 6
    int lb = *(s.lower_bound(5));// returns it greater than or equals to 5
    // lower_bound(4) = 4
    // set.lower_bound(val) gives the ceiling of val in the set.
    cout << lb << endl;
    return 0;
}

/*
| i | arr\[i] | seen      | lower\_bound             | res\[i] |
| - | ------- | --------- | ------------------------ | ------- |
| 0 | 2       | {}        | none                     | -1      |
| 1 | 5       | {2}       | 5 → end()    → back to 2 | 2       |
| 2 | 3       | {2, 5}    | 3 → 5        → back to 2 | 2       |
| 3 | 7       | {2, 3, 5} | 7 → end()    → back to 5 | 5       |


| Function         | Returns                               | Think of it as       |
| ---------------- | ------------------------------------- | -------------------- |
| `lower_bound(x)` | Iterator to the **first element ≥ x** | **Ceil(x)**          |
| `upper_bound(x)` | Iterator to the **first element > x** | **Strictly after x** |


set<int> s = {1, 3, 5, 7};

auto it1 = s.lower_bound(5);  // points to 5
auto it2 = s.upper_bound(5);  // points to 7

*/