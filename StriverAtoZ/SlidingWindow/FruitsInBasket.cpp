// https://leetcode.com/problems/fruit-into-baskets/
/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

*/
#include <vector>
#include <unordered_map>
using namespace std;

// https://www.naukri.com/code360/problems/distinct-characters_2221410?leftPanelTabValue=PROBLEM

// Time complexity: O(2n)
// Space complexity: O(3)
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> basket; // {fruitType, frequency}
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); ++right)
        {
            basket[fruits[right]]++;

            // If we have more than 2 types, shrink the window from left
            while (basket.size() > 2)
            {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// O(n)
// Space complexity: O(3)
// we don't care about the valid segment instead we care about the max window we need 
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> basket; // {fruitType, frequency}
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); ++right)
        {
            basket[fruits[right]]++;

            // If we have more than 2 types, shrink the window from left
            if (basket.size() > 2)
            {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
