//  C program to delete vowels in a given string
#include <stdio.h>

void deleteVowels(char *str);

int main() {
    char str[] = "Hello, World!";
    
    printf("Original string: %s\n", str);

    // Delete vowels
    deleteVowels(str);

    printf("String after deleting vowels: %s\n", str);

    return 0;
}

void deleteVowels(char *str) {
    int i, j;

    for (i = 0, j = 0; str[i] != '\0'; i++) {
        // Check if the current character is a vowel
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
              str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')) {
            str[j++] = str[i];
        }
    }

    // Add null terminator at the end
    str[j] = '\0';
}
