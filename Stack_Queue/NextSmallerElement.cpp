/*
Input: [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* prints element and NSE pair 
for all elements of arr[] of size n */
void printNSE(int arr[], int n)
{
	int next, i, j;
	for (i = 0; i < n; i++)
	{
		next = -1;
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				next = arr[j];
				break;
			}
		}
		cout << arr[i] << " --> "
			<< next << endl;
	}
}

vector<int> findNextSmallerElement(const vector<int>& arr) {
   
    vector<int> result(arr.size(), -1);  
 
    stack<int> st;  
 
    for (int i = 0; i < arr.size(); ++i) {
       
        while (!st.empty() && arr[i] < arr[st.top()]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
 
    return result;
}

int main()
{
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> result = findNextSmallerElement(arr);

    cout << "Original Array is: \n";
    for (int num : arr) {
        cout << num << " ";
    }
 
    cout << "\nNext Smaller Elements: \n";
    for (int num : result) {
        cout << (num == -1 ? -1 : num) << " ";
    }

	return 0;
}
