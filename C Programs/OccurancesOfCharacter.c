//Write a program in C to count occurence of a given character in a string
#include <stdio.h>

void count(char *str,char ch);

int main(){
    char *str="Hello world";
    count(str,'l');
    return 0;
}
void count(char *str,char ch){
    int counter=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==ch){
            counter++;
        }
    }
    printf("%d",counter);
}