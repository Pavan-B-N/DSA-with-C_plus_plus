// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
#include <vector>
using namespace std;
/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.


*/
// O(2k)
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int leftSum = 0;
        // Take first k cards from the left
        for (int i = 0; i < k; i++)
        {
            leftSum += cardPoints[i]; // initial sum of first k cards
        }

        int maxPoints = leftSum;
        int rightSum = 0;

        // Remove the last card from left and pick the first card from right that is right end
        for (int i = 1; i <= k; i++)
        {
            rightSum += cardPoints[n - i]; // take from end
            leftSum -= cardPoints[k - i];  // remove from front
            maxPoints = max(maxPoints, leftSum + rightSum);
        }

        return maxPoints;
    }
};

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        if (k > n)
            return 0;

        int leftSum = 0, rightSum = 0, maxPoints = 0;

        // Take first k cards from the left
        int left = 0, right = n - 1;
        while (left < k)
        {
            leftSum += cardPoints[left++];
        }

        maxPoints = leftSum;
        left--;

        // Remove the last card from left and pick the first card from right that is right end
        while (left >= 0)
        {
            rightSum += cardPoints[right--];
            leftSum -= cardPoints[left--];
            maxPoints = max(maxPoints, leftSum + rightSum);
        }

        return maxPoints;
    }
};
