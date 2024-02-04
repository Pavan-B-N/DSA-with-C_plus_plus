#include <iostream>
#include <string>
#define dbl1(x) x+x
#define dbl2(x) 2*x

using namespace std;

int main()
{
    int a=10;  
    int *p=&a;
    cout<<*p;
}
