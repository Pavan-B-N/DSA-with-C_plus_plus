// given an array of distinct integers , print all such triplets such that they add up to a specific target . the triplet should be ordered in ascenidng order
// input arr={2,4,3,7,1,8,9,0} target=6
// output={0,2,4},{1,2,3}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> threesome(vector<int> vec, int target)
{
    vector<vector<int>> res;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        int j = i + 1;
        int k = vec.size() - 1;
        while (j < k)
        {
            int sum = vec[i] + vec[j] + vec[k];
            if (target == sum)
            {
                res.push_back({vec[i], vec[j], vec[k]});
                j++;
                k--;
            }
            else if (sum > target)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    cout << endl;
    return res;
}
int main()
{
    vector<int> v = {2, 4, 3, 7, 1, 8, 9, 0};
    int target = 6;

    vector<vector<int>> res;

    res = threesome(v, target);

    for (const auto &row : res)
    {
        for (const auto &ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}