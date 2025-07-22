// https://www.geeksforgeeks.org/problems/armstrong-numbers2727/0
/*
Armstrong number is a number that is equal to the sum of cubes of its digits.

153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
*/
#include <cmath>
using namespace std;

class Solution
{
public:
    bool armstrongNumber(int n)
    {
        int sumOfCubesOfDigits = 0;
        int num = n;
        while (n != 0)
        {
            int lastDigit = n % 10;
            sumOfCubesOfDigits += pow(lastDigit, 3);
            n = n / 10;
        }
        return num == sumOfCubesOfDigits;
    }
};