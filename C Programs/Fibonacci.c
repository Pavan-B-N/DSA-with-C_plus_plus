//  Fibonacci series using recursion and iteration

#include <stdio.h>

//define function signature
void fibo_iteratively(int n);
void fibo_recursively(int n);
int fibonacci(int n);

int main(){
    int n=7;

    fibo_iteratively(n);
    fibo_recursively(n);

    return 0;
}

void fibo_iteratively(int n){
    int a=0;
    int b=1;
    int c=0;//resultant
    for(int i=0;i<n;i++){
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
    }
    printf("\n");
}

void fibo_recursively(int n){
    if(n<=0){
        return;
    }
    fibo_recursively(n-1);
    printf("%d ",fibonacci(n-1));
}
int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}