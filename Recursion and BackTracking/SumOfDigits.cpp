// 123 = 1+2+3 = 6
#include <iostream>
using namespace std;
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n % 10 + sum(n / 10);
}
int main()
{
    int num = 123;
    cout << sum(num);
    return 0;
}