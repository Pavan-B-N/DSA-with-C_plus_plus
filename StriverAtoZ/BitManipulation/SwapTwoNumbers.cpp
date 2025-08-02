// https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1
/*
You are given two numbers a and b. Your task is to swap the given two numbers.

Note: Try to do it without a temporary variable
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    pair<int, int> get(int a, int b)
    {
        a = a ^ b;
        b = a ^ b; // b = (a^b) ^ b = a
        a = a ^ b; // a = (a^b) ^ a = b
        return {a, b};
    }
};