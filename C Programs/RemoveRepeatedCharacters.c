// remove repeated character from string
#include <stdio.h>
#include <string.h>

void removeDuplicates(char str[], int length) {
    for (int i = 0; i < length; i++) {
        if (str[i] != '\0') {
            for (int j = i + 1; j < length; j++) {
                // If a duplicate is found, mark it as removed
                if (str[i] == str[j]) {
                    for (int k = j; k < length - 1; k++) {
                        str[k] = str[k + 1];
                    }
                    str[length - 1] = '\0';
                    j--; // Decrement j to re-check the current index in the next iteration
                }
            }
        }
    }
}

int main() {
    char inputString[100];

    // Get input string from the user
    printf("Enter a string: ");
    gets(inputString);

    // Calculate the length of the input string
    int length = strlen(inputString);

    // Remove duplicates from the string
    removeDuplicates(inputString, length);

    // Display the string after removing duplicates
    printf("String after removing duplicates: %s\n", inputString);

    return 0;
}
