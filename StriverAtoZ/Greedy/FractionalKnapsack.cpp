// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
/*
Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
*/
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // priority_queue of {ratio, value, weight}
        // A tuple is a fixed-size collection of elements of different types
        priority_queue<tuple<double, int, int>> maxHeap;

        for (int i = 0; i < val.size(); i++)
        {
            double ratio = (double)val[i] / wt[i];
            maxHeap.push(make_tuple(ratio, val[i], wt[i])); // ✅ use make_tuple
        }

        double maxVal = 0.0;

        while (!maxHeap.empty() && capacity > 0)
        {
            double ratio;
            int value, weight;
            //    double ratio = get<0>(top);
            tie(ratio, value, weight) = maxHeap.top();
            maxHeap.pop();

            if (weight <= capacity)
            {
                maxVal += value;
                capacity -= weight;
            }
            else
            {
                maxVal += ratio * capacity;
                break;
            }
        }

        return maxVal;
    }
};
