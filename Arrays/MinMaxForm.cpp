/*
Given a sorted array of positive integers
Rearrange an array in maximum minimum form using Two Pointer Technique

Input: arr[] = {1, 2, 3, 4, 5, 6, 7}
Output: arr[] = {7, 1, 6, 2, 5, 3, 4}

Input: arr[] = {1, 2, 3, 4, 5, 6}
Output: arr[] = {6, 1, 5, 2, 4, 3}
*/

#include <iostream>
#include <vector>
using namespace std;
void minMaxForm(vector<int> &arr)
{
    int n = arr.size();
    int j = 0;
    int k = n - 1;
    vector<int> temp;
    while (j <= k)
    {
        temp.push_back(arr[k--]);
        if(j<=k)
            temp.push_back(arr[j++]);
    }

    // Copy temp[] to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    cout << "\nArray\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    minMaxForm(arr);

    cout << "\nModified Array\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}