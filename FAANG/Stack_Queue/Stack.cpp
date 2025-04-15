#include <iostream>
using namespace std;

const int CAPACITY = 5; // Maximum size of the stack

class ArrayStack
{
private:
    int arr[CAPACITY];
    int top;

public:
    ArrayStack()
    {
        top = -1;
    }

    void push(int n)
    {
        if (isFull())
        {
            cout << "Stack Overflow, Cannot perform push operation";
            return;
        }
        arr[++top] = n;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Stack underflow, Cannot perform pop operation";
            return;
        }
        --top;
    }
    // peek
    int peek()
    {
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
    int size()
    {
        return top + 1;
    }

    bool isFull()
    {   
        return top >= CAPACITY - 1;
    }

    void display()
    {
       cout<<("\n----------")<<endl;
        for (int i = top; i >= 0; i--)
        {
            cout<<"| " << arr[i] << " |"<<endl;
        }
        cout<<("----------\n")<<endl;
    }
};

int main()
{
    ArrayStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    stack.display();

    stack.pop();
    stack.pop();

    stack.display();
    stack.push(60);
    stack.push(70);
    // stack.push(80);//stack overflow
    stack.display();
    cout<<"top= "<<stack.peek()<<endl;
    return 0;
}