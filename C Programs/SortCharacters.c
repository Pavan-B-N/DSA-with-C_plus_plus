#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int length = strlen(str);
    char temp;

    // Bubble Sort algorithm to sort characters
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                // Swap characters 
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char inputString[100];

    // Get input string from the user
    printf("Enter a string: ");
    gets(inputString);

    // Sort characters in the string
    sortString(inputString);

    // Display the sorted string
    printf("Sorted String: %s\n", inputString);

    return 0;
}
