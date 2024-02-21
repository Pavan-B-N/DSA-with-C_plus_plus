/*
input: 123
output: 321
*/
#include <iostream>
using namespace std;

int reverse(int num, int reverseNum);

int reverseNum(int n)
{
    return reverse(n, 0);
}
int reverse(int num, int reverseNum)
{
    if (num == 0)
    {
        return reverseNum;
    }
    int r = reverseNum * 10 + num % 10;
    return reverse(num / 10, r);
}
int main(){
    int num=123;
    int rnum=reverseNum(num);
    cout<<rnum;
    return 0;
}