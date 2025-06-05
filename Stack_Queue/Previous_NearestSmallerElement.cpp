// https://www.interviewbit.com/problems/nearest-smaller-element/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmaller(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top();
        }
        st.push(arr[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = prevSmaller(arr);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
