// Write a method in C which will remove any given character from a string

#include <stdio.h>

void removeChar(char *str,char ch);

int main(){
    // char *str="popcorn";
    char str[]="popcorn";

    removeChar(str,'o');

    printf("%s ",str);

    return 0;
}
void removeChar(char *str,char ch){
    int j=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=ch){
            str[j++]=str[i];
        }
    }
    str[j]='\0';
}