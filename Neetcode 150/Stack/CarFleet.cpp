// https://leetcode.com/problems/car-fleet/
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, double>> cars; // {position, time to reach target}

        // Calculate time = (target - pos) / speed for each car
        for (int i = 0; i < n; ++i)
        {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort cars by position in descending order (start from the closest to target)
        sort(cars.rbegin(), cars.rend());

        stack<double> st; // stack to store fleet arrival times

        for (auto &[pos, time] : cars)
        {
            // If current car takes more time than car in front, it's a new fleet
            if (st.empty() || time > st.top())
            {
                st.push(time);
            }
            // Else, it merges with fleet ahead (no push)
        }

        return st.size(); // number of distinct fleets
    }
};
