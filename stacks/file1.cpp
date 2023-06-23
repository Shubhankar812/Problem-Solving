#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack <int> s;

    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;

    s.pop();
    cout<<"size : "<<s.size()<<endl;
    s.pop();

    cout<<s.top()<<endl;

    if(s.empty()) {
        cout<<"Empty stack"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
}