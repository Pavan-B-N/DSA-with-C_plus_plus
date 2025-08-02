// https://www.naukri.com/code360/problems/bit-manipulation_8142533?leftPanelTabValue=PROBLEM
#include <vector>
using namespace std;

vector<int> bitManipulation(int num, int i)
{
    int bit = (num >> (i - 1)) & 1;       // Get the ith bit (1-based index)
    int setNum = num | (1 << (i - 1));    // Set the ith bit
    int clearNum = num & ~(1 << (i - 1)); // Clear the ith bit

    return {bit, setNum, clearNum};
}
