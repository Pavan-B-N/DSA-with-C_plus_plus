// Program to print all non repeating character in a string
#include <stdio.h>
#include <string.h>

void printNonRepeatingCharacters(char str[]) {
    int count[256] = {0}; // Assuming ASCII characters

    // Count occurrences of each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i]]++;
    }

    // Print non-repeating characters
    printf("Non-repeating characters in the string: ");
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[str[i]] == 1) {
            printf("%c ", str[i]);
        }
    }
    printf("\n");
}

int main() {
    char inputString[100];

    // Get input string from the user
    printf("Enter a string: ");
    gets(inputString);

    // Print non-repeating characters in the string
    printNonRepeatingCharacters(inputString);

    return 0;
}
