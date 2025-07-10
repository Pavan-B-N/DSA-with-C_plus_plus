// https://leetcode.com/problems/detect-squares/
#include <vector>
#include <unordered_map>
using namespace std;

class DetectSquares
{
public:
    unordered_map<int, unordered_map<int, int>> hashMap;

    void add(vector<int> point)
    {
        int x1 = point[0], y1 = point[1];
        hashMap[x1][y1]++;
    }

    int count(vector<int> point)
    {
        // given points
        int x1 = point[0], y1 = point[1];
        int numOfSquares = 0;

        // Iterate through all possible y2 such that (x1, y2) exists
        // finding all the vertical points that stays at x1
        for (auto &[y2, countY2] : hashMap[x1])
        {
            if (y2 == y1)
                continue;

            int sideLen = abs(y2 - y1);

            // Try square on the right: x2 = x1 + sideLen
            int x2 = x1 + sideLen;
            if (hashMap.count(x2))
            {
                if (hashMap[x2].count(y1) && hashMap[x2].count(y2))
                {
                    int c1 = hashMap[x2][y1]; // (x2, y1)
                    int c2 = hashMap[x2][y2]; // (x2, y2)
                    numOfSquares += countY2 * c1 * c2;
                }
            }

            // Try square on the left: x2 = x1 - sideLen
            x2 = x1 - sideLen;
            if (hashMap.count(x2))
            {
                if (hashMap[x2].count(y1) && hashMap[x2].count(y2))
                {
                    int c1 = hashMap[x2][y1]; // (x2, y1)
                    int c2 = hashMap[x2][y2]; // (x2, y2)
                    numOfSquares += countY2 * c1 * c2;
                }
            }
        }

        return numOfSquares;
    }
};
