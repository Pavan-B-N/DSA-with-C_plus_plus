// Palindrome or not using recursion

#include <stdio.h>
#include <string.h> // strlen , strcmp , strcpy


void swap(char *a,char *b);
char* reverse_string(char *str);

// Note the above functions are used by swap_iter so they must be declared before this
void palindrome_itr(char *str);
// void swap_iter(char str[]);
int isPalindrome(char *str,int start,int end);
void palidrome_test_recurr(char *str);

int main()
{
    char str[] = "MOM";

    palindrome_itr(str);

    palidrome_test_recurr(str);
}



// string palindrome testing using recursion
int isPalindrome(char *str,int start,int end){
    if(start>end){
        return 1;// palindrome
    }
    //compare start and end of the string
    if(str[start]!=str[end]){
        return 0;// not a palindrome
    }
    return isPalindrome(str,++start,--end);
}

void palidrome_test_recurr(char *str){
    if(isPalindrome(str,0,strlen(str)-1)){
        printf("The given string '%s' is a palindrom\n",str);
    }else{
          printf("The given string '%s' is not a palindrom\n",str);
    }
}
// string palindrome using iteration method
void palindrome_itr(char *str)
{
    char *strcp;// copy of the string is stored here
    strcpy(strcp,str);

    // we can also directly compare it instead of reversing the string
    char *reverse=reverse_string(str);
    
    if(strcmp(strcp,reverse)==0){
        printf("The given string '%s' is a palindrom\n",strcp);
    }else{
        printf("The given string '%s' is not a palindrom\n",strcp);
    }
}

char* reverse_string(char *str){
    int len = strlen(str);

    int i=0;
    int j=len-1;

    while(i<j){
        swap(&str[i],&str[j]);
        i++;
        j--;
    }
    return str;
}

void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
