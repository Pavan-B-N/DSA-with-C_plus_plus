// convert lower case upper case and vice versa
/*
Ascii values range:
a-z : 97-122
A-Z : 65-90

97+65 - 65 = 97
str[i] - 97+65 or str[i] - 'a'+'A'
but it converts vice versa

//check the condition and perform otherwise it will lead to unknown ascii
//convert to uppercase
str[i]-'a'+'A'
//convert to lowercase
str[i]-'A'+'a'
*/
#include <stdio.h>

void caseConvert(char *str);

int main()
{
    char str[] = "hello";
    caseConvert(str);
    printf("%s\n", str);

    caseConvert(str);
    printf("%s\n",str);

    return 0;
}
void caseConvert(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            // Convert lowercase to uppercase
            str[i] = str[i] - 'a' + 'A';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            // Convert uppercase to lowercase
            str[i] = str[i] - 'A' + 'a';
        }
    }
}