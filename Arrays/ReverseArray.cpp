#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    reverseArray(nums, 0, nums.size() - 1);

    cout << "Reversed array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}