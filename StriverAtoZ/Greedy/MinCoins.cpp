// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
#include <vector>
using namespace std;
/*
Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of coins required.


Example 1:

Input: N = 43
Output: 20 20 2 1
Explaination:
Minimum number of coins and notes needed
to make 43.

*/
class Solution
{
public:
    vector<int> minPartition(int N)
    {
        vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> result;

        for (int coin : coins)
        {
            while (N >= coin)
            {
                N -= coin;
                result.push_back(coin);
            }
        }

        return result;
    }
};
