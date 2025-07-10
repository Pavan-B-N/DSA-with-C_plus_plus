// https://leetcode.com/problems/happy-number/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int slow, fast;
        slow = fast = n;
        do
        {
            slow = sumOfSQOfDigits(slow);
            fast = sumOfSQOfDigits(sumOfSQOfDigits(fast));
        } while (slow != fast);

        if (slow == 1)
        {
            return true;
        }
        return false;
    }

    int sumOfSQOfDigits(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int lastdigit = n % 10;
            sum += pow(lastdigit, 2);
            n /= 10;
        }

        return sum;
    }
};