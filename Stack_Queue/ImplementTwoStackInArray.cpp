// https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1
#include <iostream>
using namespace std;

// two pointer method
class twoStacks
{
public:
	int *arr;
	int top1, top2;
	int capacity;
	twoStacks()
	{
		capacity = 100;
		arr = new int[capacity];
		top1 = -1;
		top2 = capacity;
	}
	bool isFull()
	{
		return top2 - top1 == 1;
	}
	// Function to push an integer into the stack1.
	void push1(int x)
	{
		// code here
		if (isFull())
		{
			return;
		}

		arr[++top1] = x;
	}

	// Function to push an integer into the stack2.
	void push2(int x)
	{
		if (isFull())
		{
			return;
		}

		arr[--top2] = x;
	}

	// Function to remove an element from top of the stack1.

	int pop1()
	{
		// code here
		if (top1 == -1)
		{
			return -1;
		}
		return arr[top1--];
	}

	// Function to remove an element from top of the stack2.
	int pop2()
	{
		// code here
		if (top2 == capacity)
		{
			return -1;
		}

		return arr[top2++];
	}
};