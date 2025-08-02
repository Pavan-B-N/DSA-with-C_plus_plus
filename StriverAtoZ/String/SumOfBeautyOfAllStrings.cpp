// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
#include <unordered_map>
using namespace std;

// O(n^2 * 26) = O(n²)
// Each substring has to be evaluated for beauty which depends on the frequency — can't avoid processing each substring at least once
class Solution
{
public:
    int beautySum(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            unordered_map<char, int> freqMap;
            for (int j = i; j < s.size(); j++)
            {
                freqMap[s[j]]++;

                int maxFreq = 0;
                int minFreq = INT_MAX;
                for (auto &entry : freqMap)
                {
                    maxFreq = max(maxFreq, entry.second);
                    minFreq = min(minFreq, entry.second);
                }

                sum += (maxFreq - minFreq);
            }
        }
        return sum;
    }
};
