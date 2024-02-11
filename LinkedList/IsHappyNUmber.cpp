// A happy number is a number that, when you repeatedly replace it with the sum of the squares of its digits, eventually reaches the number 1.
/*
num = 19;// true
squares
19 = 82
82 = 68
68 = 100
100 = 1
slow = 82 fast = 68
slow = 68 fast = 1
slow = 100 fast = 1
slow = 1 fast = 1
*/
#include <iostream>
using namespace std;
int sumOfSquareOfDigits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        int lastDigit = n % 10;
        ans += lastDigit * lastDigit;
        n = n / 10;
    }
    return ans;
}
bool IsHappyNumber(int num)
{
    int slow = num;
    int fast = num;
    do
    {
        slow = sumOfSquareOfDigits(slow);
        fast = sumOfSquareOfDigits(sumOfSquareOfDigits(fast));
    } while (slow != fast);
    // when slow and fast became equivalent means we got the same number
    if (slow == 1)
    {
        return true;
    }
    return false;
}

int main(){
    int n=19;// true
    // int num = 2;// false
    cout<<IsHappyNumber(n)<<endl;
    return 0;
}