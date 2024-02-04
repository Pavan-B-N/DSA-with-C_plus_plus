// Prime or not
/*
A prime number is a positive integer greater than 1 that has exactly two factors: 1 and the number itself.
*/

#include <stdio.h>

void isprime(int num);

int main(){
    int num=57;

    isprime(num);
    
    return 0;
}

void isprime(int num){
    for(int i=2;i<num;i++){
        if(num%i==0){
            printf("The number %d is not a prime number. because it is divisable by other numbers like %d \n",num,i);
            return;
        }
    }
    printf("The number %d is a prime number.\n",num);
}