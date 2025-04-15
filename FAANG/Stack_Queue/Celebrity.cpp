/*/
celebrity known to everyone but he does not know anyone

Input:
MATRIX = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0} }
Output: id = 2
Explanation: The person with ID 2 does not know anyone but everyone knows him

*/

// solved using graph, recursion, stack

#include <iostream>
#include <stack>
using namespace std;

// Number of persons (vertices) in the party
#define N 4

// Knowing matrix such that arr[i][j] == 1 means person i knows person j
int arr[N][N] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}
};

// Function to find celebrity
int findCelebrity()
{
    stack<int> s;

    // Push all people onto the stack
    for (int i = 0; i < N; i++)
        s.push(i);

    // Pop off the top two persons from the stack, until only one person remains
    while (s.size() > 1) {
        int person1 = s.top();
        s.pop();
        int person2 = s.top();
        s.pop();

        // If person1 knows person2, person1 can't be the celebrity, so person2 might be the celebrity.
        if (arr[person1][person2] == 1)
            s.push(person2);
        // If person1 doesn't know person2, person1 might be the celebrity.
        else
            s.push(person1);
    }

    // Potential celebrity candidate
    int celebrity = s.top();
    s.pop();

    // Check if the potential celebrity is actually a celebrity
    for (int i = 0; i < N; i++) {
        // If the potential celebrity knows someone or someone doesn't know the potential celebrity, they can't be the celebrity
        if (i != celebrity && (arr[celebrity][i] == 1 || arr[i][celebrity] == 0))
            return -1;
    }

    // If the loop completes, the potential celebrity is indeed a celebrity
    return celebrity;
}

int main()
{
    int celeb = findCelebrity();
    if (celeb == -1)
        cout << "No celebrity";
    else
        cout << "Celebrity ID: " << celeb;

    return 0;
}
