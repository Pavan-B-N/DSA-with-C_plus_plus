// https://www.geeksforgeeks.org/problems/prime-number2314/1

// Time complexity: sqrt(n)
class Solution
{
public:
    bool isPrime(int n)
    {
        if (n < 2)
        {
            return false;
        }
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
