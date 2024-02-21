// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/

int numberOfSteps(int num)
{
    int steps = 0;
    while (num != 0)
    {
        if (num % 2 == 0)
        {
            num /= 2;
        }
        else
        {
            --num;
        }
        steps++;
    }
    return steps;
}

int numberOfStepsUsingRecursion(int num)
{
    return helper(num, 0);
}
int helper(int num, int steps)
{
    if (num == 0)
    {
        return steps;
    }
    return num % 2 == 0 ? helper(num / 2, ++steps) : helper(--num, ++steps);
}