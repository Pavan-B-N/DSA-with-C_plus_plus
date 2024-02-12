#include <iostream>

int main() {
    double arr[] = {10.0, 20.0};
    double *p, *q;
    p = arr; // first element 10
    q = p + 1;  // q=p+1 i.e second element 20
    std::cout << (int)(q - p) << std::endl; // q-p= 2004 - 2000 = 4/4 = 1 i.e difference between two pointer always returns a number of elements 
    std::cout << (int)(*q - *p) << std::endl; // *q - *p = 20 - 10 =10
    return 0;
}