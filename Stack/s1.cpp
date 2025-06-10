// **********INTRODUCTION TO STACK ***********

#include <iostream>
using namespace std;

class Stack
{

public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    void push(int n)
    {
        if (top < size - 1)
        {
            arr[++top] = n;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop()
    {
        if (top >= 0)
        {
            return arr[--top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
};

int main()
{
    Stack st(3);
    st.push(10);
    cout << "The top element is : " << st.peek() << endl;

    st.push(20);
    cout << "The top element is : " << st.peek() << endl;

    st.push(30);
    cout << "The top element is : " << st.peek() << endl;

    st.push(40);
    cout << "The top element is : " << st.peek() << endl;

    st.pop();
    cout << "The top element is : " << st.peek() << endl;

    st.pop();
    cout << "The top element is : " << st.peek() << endl;

    return 0;
}