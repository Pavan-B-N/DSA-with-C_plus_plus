// Program to replace the string space with a given character
#include <stdio.h>

void replace_white_space(char *str,char ch);

int main(){
    /*
    Note: *str -> string literal, immutable
          "" ->string , '' -> character
    */
    char str[]="Hello world !!";
    replace_white_space(str,'_');
    printf("%s",str);
    return 0;
}
void replace_white_space(char *str,char ch){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            str[i]=ch;
        }
    }
}