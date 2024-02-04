//  Write a program to reverse an integer in C
#include <stdio.h>
int main(){
    int num=123;
    int n=num;//copy of the number
    //reverse
    int reverse=0;
    int lastdigit;
    while(num>0){
        lastdigit=num%10;
        num=num/10;
        reverse=reverse*10+lastdigit;
    }
    printf("Reverse of the number %d is %d",n,reverse);
}