// Frequencies in sorted array
/*
arr={10,10,10,15,15}
output:
10 - 3
15 - 2
*/

#include <stdio.h>

void frequency(int arr[]);

int main()
{

    int arr[] = {10, 10, 10, 15, 15};

    frequency(arr);
    return 0;
}

void frequency(int arr[])
{
    int n = sizeof(arr) / sizeof(arr[0]);
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        counter++;
        if (arr[i] != arr[(i + 1) % n])
        {
            printf("%d = %d \n", arr[i], counter);
            counter = 0;
        }
    }
}