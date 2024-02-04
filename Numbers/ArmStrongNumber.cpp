// Write a program to check whether an integer is Armstrong number or not
/*
Armstrong number is a number that is equal to the sum of cubes of its digits.

153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153

*/

#include <iostream>
#include <cmath>
using namespace std;
void isArmStrongNum(int num)
{
    int n = num;         // copy of num
    double cubicNum = 0; // Note when dealing with mathematical operations in c its recommended to use double as data type insstead of int

    int lastdigit;

    while (num > 0)
    {
        lastdigit = num % 10;
        num = num / 10;

        cubicNum += pow(lastdigit, 3);
    }

    if (cubicNum == n)
    {
        cout << "Yes, Given Number is a ArmStrong Number" << endl;
    }
    else
    {
        cout << "No, Given Number is not a ArmStrong Number" << endl;
    }
}

int main()
{
    int n=153;
    isArmStrongNum(n);
    return 0;
}