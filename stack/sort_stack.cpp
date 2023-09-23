#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int key)
{
    if (s.empty() || s.top() < key)
    {
        s.push(key);
        return;
    }
    int tp = s.top();
    s.pop();
    insert(s, key);

    s.push(tp);
}
void sort(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int tp = s.top();
    s.pop();
    sort(s);
    insert(s, tp);
}
void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

int main()
{
    stack<int> stk;
    stk.push(5);
    stk.push(8);
    stk.push(6);
    stk.push(7);
    stk.push(2);

    int sz = stk.size();

    display(stk);

    // Delete(stk,0,sz);
    // insert_at_bottom(stk, 100);

    sort(stk);

    display(stk);
}