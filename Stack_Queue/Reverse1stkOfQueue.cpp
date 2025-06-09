/*
Input: Queue = 1 2 3 4 5, k = 3
Output: 3 2 1 4 5
*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<int> reverseFirstK(queue<int> q, int k) {
    stack<int> s;
    
    while (k > 0) {
        s.push(q.front());
        q.pop();
        k--;
    }
    
    int remainingSizeOfQueue = q.size();
    
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    while (remainingSizeOfQueue > 0) {
        q.push(q.front());
        q.pop();
        remainingSizeOfQueue--;
    }
    
    return q;
}


int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    queue<int> result = reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

}