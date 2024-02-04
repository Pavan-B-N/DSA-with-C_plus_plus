#include <iostream>
#include <set>
using namespace std;

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 6};

    set<int> s;

    // union
    for (int i = 0; i < 5; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        s.insert(arr2[i]);
    }

    for (int elem : s)
    {
        std::cout << " " << elem;
    }

    return 0;
}