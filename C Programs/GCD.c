// gcd of a given number
// gcd(5,10) = 5

#include <stdio.h>

void gcd(int a,int b){
    int min=a>b ? b : a;
    int greatest_factor=1;
    for(int i=2;i<=min;i++){
        if(a%i==0 && b%i==0){
            greatest_factor=i;
        }
    }
    printf("GCD of %d and %d is %d",a,b,greatest_factor);
}

int main(){
    gcd(4,12);
    return 0;
}