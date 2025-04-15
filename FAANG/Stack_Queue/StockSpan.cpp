// https://www.hackerearth.com/problem/algorithm/stock-span-4-a0d4600b-b5c6efe0/
/*
Once upon a time, there was a stock trader named John. John was always looking for new ways to improve his trading strategies and make more profits. One day, he came across a problem while analyzing the stock market data.

John had a list of daily stock prices for a particular stock, and he wanted to calculate the "stock span" for each day. The stock span for a particular day is defined as the maximum number of consecutive days (including the current day) before the current day, such that the price of the stock on all those days is less than or equal to the price on the current day.

For example, if the stock prices for the last 7 days were {100, 80, 60, 70, 60, 75, 85}, then the span values for the corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

John wanted to automate this calculation process so that he could quickly analyze the stock market data and make better trading decisions. However, he was not sure how to write an efficient algorithm for this problem.

Can you help John by writing an algorithm to calculate the stock span for each day in the given list of stock prices?

Input Format

The first line contains an integer N where N is the number of days and in the next line, you have to take an integer array name prices which contains N prices.

Sample Input:

N = 7

price[] = [100 80 60 70 60 75 85]

Output:

1 1 1 2 1 4 6
*/

#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    // stock prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    // solution
    vector<int> ans(price.size(), 0);
    stack<int> s;// stores indices

    for (int i = 0; i < price.size(); i++)
    {
        while (s.size() > 0 && price[s.top()] <= price[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - s.top(); // i - prevHigh
        }

        s.push(i);
    }

    // print ans vals
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;

    return 0;
}
