// a leap year has 366 days, with an extra day added to the month of February.

// A leap year is a year that is evenly divisible by 4, except for years that are divisible by 100. However, years divisible by 400 are leap years.

#include<stdio.h>

int isLeapYear(int year) {
    // Leap year logic
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

int main() {
    int year;

    // Input year from the user
    printf("Enter a year: ");
    scanf("%d", &year);

    // Check and display the result
    if (isLeapYear(year)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}
