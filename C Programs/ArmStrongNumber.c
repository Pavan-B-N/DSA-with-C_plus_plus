// Write a program to check whether an integer is Armstrong number or not
/*
Armstrong number is a number that is equal to the sum of cubes of its digits.

153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153

*/

#include <stdio.h>
#include <math.h>

int main(){
    int num=153;
    int n=num;//copy of num
    double cubicNum=0; // Note when dealing with mathematical operations in c its recommended to use double as data type insstead of int

    int lastdigit;

    while(num>0){
        lastdigit=num%10;
        num=num/10;

        cubicNum+=pow(lastdigit,3);
    }

    if(n==(int)cubicNum){
        printf("The Number %d is a ArmStrong Number",n);
    }else{
         printf("The Number %d is not a ArmStrong Number",n);
    }

    return 0;
}