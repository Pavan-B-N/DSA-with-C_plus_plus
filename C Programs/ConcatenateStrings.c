// concatenate two strings
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc and free
char* concatenate_string(char *str1,char *str2);

int main(){
    char str1[]="Hello";
    char str2[]=" World";
    char *str3=concatenate_string(str1,str2);
    printf("%s",str3);
    // Free the allocated memory
    free(str3);
    return 0;
}
char* concatenate_string(char *str1,char *str2){
    int len1=strlen(str1);
    int len2=strlen(str2);
    int len3=len1+len2;
    int i=0;

   // Allocate memory for str3
    char *str3 = (char*)malloc(len3 * sizeof(char));

    // Check if memory allocation is successful
    if (str3 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Copy str1 to str3
    while (str1[i] != '\0') {
        str3[i] = str1[i];
        i++;
    }

    // Reset index i before starting the second loop
    i = 0;

    // Copy str2 to str3
    while (str2[i] != '\0') {
        str3[len1 + i] = str2[i];
        i++;
    }

    // Add null terminator
    str3[len1 + i] = '\0';

    return str3;
}