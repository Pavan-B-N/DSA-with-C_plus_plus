// https://leetcode.com/problems/hand-of-straights/description/
/*
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
*/
// Time complexity: O(n log n)
// Space complexity: O(n)
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> freqMap; // Sorted map: card -> frequency
        for (int card : hand)
        {
            freqMap[card]++;
        }

        while (!freqMap.empty())
        {
            int start = freqMap.begin()->first;

            for (int i = 0; i < groupSize; i++)
            {
                int card = start + i;
                if (freqMap.find(card)==freqMap.end())
                    return false;
                freqMap[card]--;
                if (freqMap[card] == 0)
                {
                    freqMap.erase(card);
                }
            }
        }

        return true;
    }
};
