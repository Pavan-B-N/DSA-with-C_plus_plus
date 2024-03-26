/*
Input: arr1[] = [ 1, 2, 3 ] , arr2[] = [ 2, 1, 3 ]
Output: YES

Input: arr1[] = [ 1, 2, 3 ] , arr2[] = [ 3, 1, 2 ]
Output: Not Possible
*/

#include <iostream>
#include <stack>
using namespace std;

bool checkStackPermutation(int ip[], int op[], int n)
{
    stack<int> s;

    // will maintain a variable j to iterate on output array
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        s.push(ip[i]);
        while (!s.empty() && s.top() == op[j])
        {
            s.pop();
            j++;
        }
    }

    if (s.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    // Input Array
    int input[] = {4, 5, 6, 7, 8};

    // Output Array
    int output[] = {8, 7, 6, 5, 4};

    int n = 5;

    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}
