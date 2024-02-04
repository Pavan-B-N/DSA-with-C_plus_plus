// alculate power without using POW ()
#include <stdio.h>

double powOfn(double base,int exponent);

int main(){
    int a=4;
    int n=4;
    printf("%lf",powOfn(a,n));
    return 0;
}

double powOfn(double base,int exponent){
    double res=1.0;

    if(exponent>0){
        for(int i=0;i<exponent;i++){
            res*=base;
        }
    }else{
        //handle negative power by taking reciprocal of the given number
        for(int i=0;i<(-exponent);i++){
            res/=base;
        }
    }
    return res;
}