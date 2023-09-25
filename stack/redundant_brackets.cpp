#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    int n=s.length();
    
    for(int i=0;i<n;i++) {
        char ch = s[i];
        
        if(ch=='(' || ch == '+' || ch == '-' || ch == '/' || ch == '*') {
            st.push(ch);
        }
        else{
            if(ch==')') {
                bool flag = true;   // returns true if the expression is redudant
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top== '*' || top=='/') {
                        flag = false;
                    }
                    st.pop(); 
                }

                if(flag){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
int main()
{
    string s = "(a+b)";
    bool ans = findRedundantBrackets(s);

    if(ans) {
        cout<<"Yes"<<endl;
    }
    cout<<"No"<<endl;
}