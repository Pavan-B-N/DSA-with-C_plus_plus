// find factorial of a number
// 5! = 5*4*3*2*1 = 120

#include <stdio.h>
int factorial(int n);
int main(){
    int n=5;
    int fact=factorial(n);
    printf("Factorial of a %d is %d",n,fact);
    return 0;
}
int factorial(int n){
    int fact=1;
    while(n>0){
        fact*=n--;
    }
    return fact;
}