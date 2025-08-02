// https://leetcode.com/problems/sort-characters-by-frequency/

// Efficient Approach: Bucket Sort
// This solution uses:

// Count frequencies using an unordered_map<char, int>.

// Create a vector of buckets: vector<vector<char>> buckets(n + 1), where
// buckets[f] holds all chars that appear exactly f times.

// Append characters from highest frequency down to build the result string.

// Time complexity: O(n) (linear pass through string, linear bucket processing)
// Space complexity: O(n
#include <string>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;
// tag: [favorite]

// o(N)
class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.size();
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }

        vector<vector<char>> buckets(n + 1);
        for (auto &it : freq)
        {
            char ch = it.first;
            int freq = it.second;
            buckets[freq].push_back(ch);
        }

        string result;
        result.reserve(n);
        for (int feq = n; feq >= 1; --feq)
        {
            for (char ch : buckets[feq])
            {
                // string& append (size_t n, char c);
                // n → how many times to repeat
                result.append(feq, ch);
            }
        }
        return result;
    }
};

// o(NLOGN)
class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.size();
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }

        map<int, vector<char>> map;
        for (auto &it : freq)
        {
            map[it.second].push_back(it.first);
        }
        string result;
        result.reserve(n);
        for (auto &it : map)
        {
            for (char ch : it.second)
            {
                result.append(it.first, ch);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
