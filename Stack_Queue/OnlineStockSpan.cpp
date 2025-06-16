// https://leetcode.com/problems/online-stock-span/

#include <iostream>
#include <stack>

using namespace std;

// O(N)
class StockSpanner
{
public:
    int currIndex = -1;
    //  monotonic stack
    // previous greater
    stack<pair<int, int>> s; // {price, index}

    StockSpanner() {}

    // O(1) amortized per call due to monotonic stack
    int next(int price)
    {
        currIndex++;

        // Pop all prices less than or equal to current price
        // because we need to store only PGE
        while (!s.empty() && s.top().first <= price)
        {
            s.pop();
        }

        int prevGreaterIndex = s.empty() ? -1 : s.top().second;
        int span = currIndex - prevGreaterIndex;

        s.push({price, currIndex});
        return span;
    }
};
