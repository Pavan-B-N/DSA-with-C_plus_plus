#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void cyclicSort(vector<int>& nums) ;

vector<int> findErrorNums(vector<int>& nums) {
    cyclicSort(nums);
    vector<int> result(2, -1);
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            result[0] = nums[i];
            result[1] = i + 1;
            break;
        }
    }
    return result;
}

void cyclicSort(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        while (i != nums[i] - 1) {
            if (nums[i] == nums[nums[i] - 1])
                break;
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 2, 4};
    vector<int> error = findErrorNums(arr);
    for (int num : error) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
