// lcm of a given two numbers
/*
    10,6
  2 5  3

  2*5*3 = 30;
*/
#include<stdio.h>

void lcm(int a,int b){
    int least_common_multiple=1;
    int min=a>b ? b : a;
    for(int i=2;i<=min;i++){
        if(a==1 || b==1){
            break;
        }
        while(a%i==0 && b%i==0){
            least_common_multiple*=i;
            a=a/i;
            b=b/i;
        }
    }
    least_common_multiple*=a*b;

    printf("LCM  is %d",least_common_multiple);
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void lcm(int a, int b) {
    int gcd_value = gcd(a, b);
    int least_common_multiple = (a / gcd_value) * b;

    printf("LCM is %d", least_common_multiple);
}

int main(){
    // lcm(5,6);
    lcm(10,6);
    return 0;
}