// Next Smaller to Right
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a)
{
    vector<int> ans;
    stack<int> s;
    int n = a.size();

    for (int i = n-1; i >= 0; i--)
    {
        if (s.empty())
            ans.push_back(-1);
        else if (!s.empty() && s.top() < a[i])
        {
            ans.push_back(s.top());
        }
        else if (!s.empty() && s.top() > a[i])
        {
            while (!s.empty() && s.top() > a[i])
            {
                s.pop();
            }
            if(s.empty())   ans.push_back(-1);
            else    ans.push_back(s.top());
        }
        s.push(a[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();

    vector<int> res = solve(arr);

    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << "\n";
}