#include <stdio.h>
#include <ctype.h>

void highestFrequencyChar(const char *inputString) {
    int charFrequency[26] = {0}; // Assuming only alphabetical characters

    // Count the frequency of each character
    for (const char *ptr = inputString; *ptr != '\0'; ++ptr) {
        if (isalpha(*ptr)) { // Consider only alphabetical characters
            charFrequency[tolower(*ptr) - 'a']++;
        }
    }

    // Find the character with the highest frequency
    int maxIndex = 0;
    for (int i = 1; i < 26; ++i) {
        if (charFrequency[i] > charFrequency[maxIndex]) {
            maxIndex = i;
        }
    }

    char maxChar = 'a' + maxIndex;
    printf("The character with the highest frequency is '%c' with a frequency of %d.\n", maxChar, charFrequency[maxIndex]);
}

int main() {
    const char *inputString = "Programming is fun";
    highestFrequencyChar(inputString);

    return 0;
}
