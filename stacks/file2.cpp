#include <iostream>
#include <vector>

using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int sz)
    {
        this->size = sz;
        arr = new int[sz];
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            top += 1;
            arr[top] = data;
        }
        else
        {
            cout << "Stack is full, cannot insert !" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack is empty, cannot pop !" << endl;
        }
    }
    int peek()
    {
        return arr[top];
    }
    bool isEmpty()
    {
        if (top >= 0)
        {
            return false;
        }
        return true;
    }
};
int main()
{
    Stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!(s.isEmpty()))
    {
        cout << s.peek() << endl;
        s.pop();
    }
    return 0;
}