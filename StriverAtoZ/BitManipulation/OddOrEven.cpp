// https://www.geeksforgeeks.org/problems/odd-or-even3618/1

class Solution
{
public:
    //   Return true if the number is even and false if the number is odd.
    bool isEven(int n)
    {
        return (n & 1) == 0;
    }
};