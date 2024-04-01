#include <stdio.h>
#include <stdlib.h>

int main(){
    int x=-5;
    if(x+abs(x)){
        printf("Positive number");
    }else{
        printf("Negative Number");
    }
    return 0;
}