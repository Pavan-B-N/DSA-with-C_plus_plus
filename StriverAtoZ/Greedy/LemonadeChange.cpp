// https://leetcode.com/problems/lemonade-change/description/
#include <vector>
#include <algorithm>
using namespace std;
/*
You are running a lemonade stand where:

Each lemonade costs $5

Customers can pay with $5, $10, or $20 bills

You must give the correct change using the money you've already received
*/
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;

        for (int bill : bills)
        {
            if (bill == 5)
            {
                five++;
            }
            else if (bill == 10)
            {
                if (five == 0)
                    return false;
                five--;
                ten++;
            }
            else
            { // bill == 20
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};
