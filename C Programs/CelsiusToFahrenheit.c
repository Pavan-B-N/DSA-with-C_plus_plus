// Celsius to Fahrenheit
// F= ( 9/5 *c )+ 32
#include<stdio.h>

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

int main() {
    float celsius, fahrenheit;

    // Input temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = celsiusToFahrenheit(celsius);

    // Display the result
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

    return 0;
}
