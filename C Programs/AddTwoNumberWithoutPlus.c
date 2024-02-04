// add two numbers without using  arithmetic operator '+'

//use bitwise operators

#include <stdio.h>

int add(int a,int b);
int subtract(int a,int b);
int multiply(int a,int b);
int divide(int dividend,int divisor);

int main(){
    int a=2;
    int b=3;

    printf("Addition %d\n",add(a,b));
    printf("Subtraction %d\n",subtract(a,b));
    printf("Multiplication %d\n",multiply(a,b));
    printf("Division %d\n",divide(a,b));
    return 0;
}
int add(int a,int b){
    int carry;
    while(b!=0){
        carry=a&b;
        a=a^b;
        b=carry<<1;
    }
    return a;
}
int subtract(int a,int b){
    while(b!=0){
        int borrow= ~a & b;
        a=a^b;
        b=borrow<<1;
    }
    return a;
}

int multiply(int a,int b){
    int res=0;
    while(b>0){
        if(b&1!=0){
            res+=a;
        }
        a=a<<1;
        b=b>>1;
    }
    return res;
}

int divide(int dividend,int divisor){
    int quotient=0;
    while(dividend>=divisor){
        dividend=dividend-divisor;
        quotient++;
    }
    //print remainder
    int remainder=dividend+divisor;
    printf("Remainder is %d  \n",remainder);
    // printf("Quotient %d is \n",quotient);
    return dividend;
}