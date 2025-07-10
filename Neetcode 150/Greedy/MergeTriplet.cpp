// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
#include <vector>
using namespace std;

class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        vector<bool> isMatched(3, false);

        for (auto &triplet : triplets)
        {
            int a = triplet[0], b = triplet[1], c = triplet[2];

            // Only consider triplets that can be part of the final merge
            if (a <= target[0] && b <= target[1] && c <= target[2])
            {
                if (a == target[0])
                    isMatched[0] = true;
                if (b == target[1])
                    isMatched[1] = true;
                if (c == target[2])
                    isMatched[2] = true;
            }
            if (isMatched[0] && isMatched[1] && isMatched[2])
            {
                return true;
            }
        }

        return false;
    }
};
