//  program to check given character is digit or not
#include <stdio.h>
int is_digit(char ch);

int main()
{
    char ch = '7';

    if (is_digit(ch))
    {
        printf("The character is a digit.\n");
    }
    else
    {
        printf("The character is not a digit.\n");
    }
    return 0;
}

int is_digit(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}