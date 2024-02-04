#include <stdio.h>

void countVowelsAndConsonants(char *str, int *vowels, int *consonants);

int main()
{
    char str[100];
    int vowels = 0, consonants = 0;

    // Input a string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Count vowels and consonants
    countVowelsAndConsonants(str, &vowels, &consonants);

    // Display the results
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}

void countVowelsAndConsonants(char *str, int *vowels, int *consonants)
{
    // Iterate through the string
    for (int i = 0; str[i] != '\0'; i++)
    {
        // Check if the current character is an alphabet letter
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            // Check if the current character is a vowel
            if ((str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                  str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'))
            {
                (*vowels)++;
            }
            else
            {
                (*consonants)++;
            }
        }
    }
}
