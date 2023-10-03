// Next Greater to Left

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a)
{
    vector<int> ans;
    stack<int> s;

    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else if (!s.empty() && s.top() > a[i])
        {
            ans.push_back(s.top());
        }
        else if (!s.empty() && s.top() < a[i])
        {
            while (!s.empty() && s.top() < a[i])
            {
                s.pop();
            }
            if(s.empty()) {
                ans.push_back(-1);
            }
        }
        s.push(a[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 3, 2, 4};
    int n = arr.size();

    vector<int> res = solve(arr);

    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << "\n";
}
