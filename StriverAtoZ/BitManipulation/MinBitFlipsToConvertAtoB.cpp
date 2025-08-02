
// brute force
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int minFlips = 0;

        // Compare each bit of start and goal
        while (start > 0 || goal > 0)
        {
            int i = start & 1;
            int j = goal & 1;
            if (i != j)
                minFlips++;

            start >>= 1;
            goal >>= 1;
        }

        return minFlips;
    }
};

// optimal
// TC: O(31)
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int xorVal = start ^ goal;
        int count = 0;
        while (xorVal)
        {
            // turning off rightmost set bits
            xorVal &= (xorVal - 1); // Brian Kernighan's algorithm
            count++;
        }
        return count;
    }
};
