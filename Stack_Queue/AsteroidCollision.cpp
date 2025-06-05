// https://leetcode.com/problems/asteroid-collision/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;

        for (int asteroid : asteroids)
        {
            bool survived = true;

            while (!s.empty() && asteroid < 0 && s.top() > 0)
            {
                if (abs(asteroid) > abs(s.top()))
                {
                    s.pop(); // top explodes, keep checking
                }
                else if (abs(asteroid) == abs(s.top()))
                {
                    s.pop(); // both explode
                    survived = false;
                    break;
                }
                else
                {
                    survived = false; // current asteroid explodes
                    break;
                }
            }

            if (survived)
            {
                s.push(asteroid);
            }
        }

        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; --i)
        {
            result[i] = s.top();
            s.pop();
        }

        return result;
    }
};