// C program to separate characters in a given string
#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100], separatedString[200];
    int i, j = 0;

    // Get input string from the user
    printf("Enter a string: ");
    gets(inputString);

    // Separate characters in the string
    for (i = 0; i < strlen(inputString); i++) {
        separatedString[j++] = inputString[i];
        separatedString[j++] = ' '; // Add a space between characters
    }

    // Null-terminate the separated string
    separatedString[j] = '\0';

    // Display the separated string
    printf("Separated String: %s\n", separatedString);

    return 0;
}
