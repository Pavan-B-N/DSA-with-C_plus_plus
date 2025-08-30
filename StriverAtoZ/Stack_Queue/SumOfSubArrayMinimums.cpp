// https://leetcode.com/problems/sum-of-subarray-minimums/
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int res = 0;
        int n = arr.size();
        stack<int> s; // stores indices
        int mod = 1e9 + 7;
        // previous smaller element
        for (int i = 0; i <= n; i++)
        {
            while (!s.empty() && (i == n || arr[s.top()] > arr[i]))
            {
                int curr = s.top();
                s.pop();

                int nse = i;
                int pse = s.empty() ? -1 : s.top();
                int left = curr - pse;
                int right = nse - curr;
                long long contributions = left * right;
                res = (res + arr[curr] * contributions) % mod;
            }
            s.push(i);
        }

        return res;
    }
};

// O(N)
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(n), next(n); // count contributions, unitl index
        stack<int> s;

        // Previous Smaller Element
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] > arr[i])
                s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long res = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            long long left = i - prev[i];
            long long right = next[i] - i;
            long long totalContributions = left * right;
            res = (res + arr[i] * totalContributions) % mod;
        }

        return (int)res;
    }
};

// o(N^2) , TLE
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int sum = 0;
        int mod = 1e9 + 7; // 10^9 + 7
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int minVal = INT_MAX;
            for (int j = i; j < n; j++)
            {
                minVal = min(minVal, arr[j]);
                sum = (sum + minVal) % mod;
            }
        }
        return sum;
    }
};