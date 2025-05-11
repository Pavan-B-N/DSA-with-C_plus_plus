#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void permutations(string p, string up)
{
    if (up.empty())
    {
        cout << p << endl;
        return;
    }

    char ch = up[0];

    for (int i = 0; i <= p.length(); i++)
    {
        string f = p.substr(0, i);
        string s = p.substr(i);
        permutations(f + ch + s, up.substr(1));
    }
}

int permutationsCount(string p, string up)
{
    if (up.empty())
    {
        cout << p << endl;
        return 1;
    }

    char ch = up[0];

    int count = 0;
    for (int i = 0; i <= p.length(); i++)
    {
        string f = p.substr(0, i);
        string s = p.substr(i);
        count += permutationsCount(f + ch + s, up.substr(1));
    }
    return count;
}

// https://leetcode.com/problems/permutations/
// approach 2 = optimal
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    findPermutations(nums, ans, 0);
    return ans;
}

void findPermutations(vector<int> &nums, vector<vector<int>> &ans, int index)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        findPermutations(nums, ans, index + 1);
        swap(nums[i], nums[index]);
    }
}

// apparoach 1 = okay okay
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> permutation;
    set<int> s;
    findPermutations(nums, ans, s, permutation);
    return ans;
}

void findPermutations(vector<int> &nums, vector<vector<int>> &ans, set<int> &s, vector<int> &permutation)
{
    if (permutation.size() == nums.size())
    {
        ans.push_back(permutation);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(i) == s.end())
        {
            s.insert(i);
            permutation.push_back(nums[i]);
            findPermutations(nums, ans, s, permutation);
            permutation.pop_back();
            s.erase(i);
        }
    }
}

int main()
{
    permutations("", "abc");
    // cout<<permutationsCount("","abc");
    return 0;
}
