
#include <iostream>
using namespace std;

class Solution
{
public:
    void factorial(int n)
    {
        cout << fact(n);
    }

private:
    int fact(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        return n * fact(n - 1);
    }
};
