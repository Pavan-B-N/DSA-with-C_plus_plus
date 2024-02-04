#include <iostream>
#include <cmath>
using namespace std;

// Newton's Raphson method
double sqrt_num(double n)
{
    double x = n / 2; // initial approximation
    double root = 0.5 * (x + n / x);
    // trying to find the root until i find the error that is greater than 0.0001
    // Error = Math.abs(root-x)
    // error>1 also okay
    while (abs(root - x) > 0.0001)
    {
        x = root;
        root = 0.5 * (x + n / x);
    }
    return root;
}
int main()
{
    int n=10;
    printf("%.4f",sqrt_num(n));
    return 0;
}