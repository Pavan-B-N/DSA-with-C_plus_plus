/*
https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).


{distance,petrol unit}
*/

#include <iostream>
using namespace std;

// A petrol pump has petrol and distance to next petrol pump 
class petrolPump {
public:
    int petrol; 
    int distance; 
}; 

// The function returns starting point if there is a possible solution, 
// otherwise returns -1 
int printTour(petrolPump arr[], int n) {
    int totGas = 0, totCost = 0;
    int start = 0, currGas = 0;

    for (int i = 0; i < n; i++) { // O(n)
        totGas += arr[i].petrol;
        totCost += arr[i].distance;
        currGas += (arr[i].petrol - arr[i].distance);

        if (currGas < 0) {
            start = i + 1;
            currGas = 0;
        }
    }

    return totGas < totCost ? -1 : start;
}

// Driver code 
int main() { 
    petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}}; 

    int n = sizeof(arr) / sizeof(arr[0]); 
    int start = printTour(arr, n); 

    (start == -1) ? cout << "No solution" : cout << "Start = " << start; 

    return 0; 
} 

// This code is contributed by rathbhupendra
