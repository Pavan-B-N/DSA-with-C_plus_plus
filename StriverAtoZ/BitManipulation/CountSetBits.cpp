// https://www.geeksforgeeks.org/problems/set-bits0143/1

class Solution
{
public:
    int setBits(int n)
    {
        int count = 0;
        while (n > 0)
        {
            if (n & 1)   // if condition not required
                count++; // count+=(n&1);// n&1 return 0 or 1
            n = n >> 1;
        }
        return count;
    }
};

// better
class Solution
{
public:
    int setBits(int n)
    {
        int count = 0;
        // turnOff rightmost set bit
        while (n > 0)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};