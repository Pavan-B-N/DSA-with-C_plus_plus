#include <stdio.h>

void trim(char *str){
    int inWord=0;
    int j=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=' '){
            inWord=1;
            str[j++]=str[i];
        }else if(inWord){
            str[j++]=' ';
            inWord=0;
        }
    }
    if(str[j]==' '){
        j--;
    }
    str[j]='\0';
}

// for constant pointer
char* trim2(char *str){
    char *output;
    int inWord=0;
    int j=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=' '){
            inWord=1;
            output[j++]=str[i];
        }else if(inWord){
            output[j++]=' ';
            inWord=0;
        }
    }
    if(str[j-1]==' '){
        j--;
    }
    output[j]='\0';
    return output;
}
int main(int argc, char const *argv[])
{
    //constant pointer
    char *str="      hello       world          ";
    str=trim2(str);

    // char str[]="      hello       world          ";
    // trim(str);

    printf("%sEnd",str);

    return 0;
}
