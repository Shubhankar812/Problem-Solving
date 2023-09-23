#include <bits/stdc++.h>
using namespace std;


void Delete(stack<int> &s,int c,int sz) {
    
    if(c==sz/2) {
        s.pop();
        return;
    }
    int top = s.top();
    s.pop();
    Delete(s,c+1,sz);
    s.push(top);
}
void display(stack<int> s) {
    while (!s.empty()) 
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
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

    Delete(stk,0,sz);

    display(stk);
}