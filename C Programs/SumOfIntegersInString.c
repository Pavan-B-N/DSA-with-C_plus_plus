// sum of integers in a given string
#include <stdio.h>

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int strToInt(char str[], int start, int end) {
    int result = 0;
    for (int i = start; i <= end; i++) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

int sumOfIntegers(char str[]) {
    int sum = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (isDigit(str[i])) {
            int start = i;
            while (isDigit(str[i])) {
                i++;
            }
            int end = i - 1;
            sum += strToInt(str, start, end);
        } else {
            i++;
        }
    }

    return sum;
}

int main() {
    char inputString[100];

    // Get input string from the user
    printf("Enter a string containing integers: ");
    gets(inputString);

    // Calculate the sum of integers in the string
    int result = sumOfIntegers(inputString);

    // Display the result
    printf("Sum of integers in the string: %d\n", result);

    return 0;
}
