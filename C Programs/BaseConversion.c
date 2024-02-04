#include <stdio.h>

// decimal to binary
void decimalToBinary(int decimal)
{
    if (decimal == 0)
    {
        printf("Binary: 0");
        return;
    }

    int binary[32]; // Assuming a 32-bit binary representation
    int i = 0;

    while (decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    // printing in reverse order
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
    printf("\n");
}
void decimalToOctal(int decimal)
{
    if (decimal == 0)
    {
        printf("Octal: 0");
        return;
    }

    int octal[32]; // Assuming a 32-bit octal representation
    int i = 0;

    while (decimal > 0)
    {
        octal[i] = decimal % 8;
        decimal = decimal / 8;
        i++;
    }
    // printing in reverse order
    printf("Octal: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
    }
    printf("\n");
}

int main()
{
    decimalToBinary(10);
    decimalToOctal(10);
    return 0;
}