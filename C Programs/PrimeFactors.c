// Prime factors of a given number
/*
A prime factor of a number is a prime number that divides that number exactly, without leaving a remainder.

example 36
factors - 2,3,4,6,18,36
prime factors - 2,3
*/

#include <stdio.h>

void primeFactors(int n);
void printPrimeFactors(int n);

int main(){
    int n=36;
    // printPrimeFactors(n);
    primeFactors(n);
    return 0;
}


void primeFactors(int n){
    // first divide the number by 2
    while(n%2==0){
        printf("%d ",2);
        n=n/2;
    }

    //now start from 3 and adding odd numbers to it
    for(int i=3;i<=n;i+=2){
        while(n%i==0){
            printf("%d ",i);
            n=n/i;
        }
    }
    if(n>1)
        printf("%d ",n);
}

//sieve of eratosthenes
void printPrimeFactors(int n){
    // use sieve of eratosthenes method to generate prime numbers between the given number
    n=n+1;//because i want to match array values and elements
    int arr[n];
    // initialize array
    for(int i=0;i<=n;i++){
        arr[i]=i;
    }
    // 1 2 3 4 5 6 ...
    arr[1]=0;//1 is not a prime number
    //start from 2 to root n
    for(int i=2;i*i<=n;i++){
        if(arr[i]!=0){
            for(int j=i*i;j<n;j+=i){
                arr[j]=0;
            }
        }
    }

    //now print only prime factors
    for(int i=0;i<=n;i++){
        if(arr[i]!=0 && (n-1)%arr[i]==0 ){
            printf("%d ",arr[i]);
        }
    }

}