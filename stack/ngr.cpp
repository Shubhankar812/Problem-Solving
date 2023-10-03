// Next Largest Element or Nearest Greater to Right

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a)
{
    int n = a.size();
    stack<int> s;
    vector<int> ans;

    for (int i = n-1; i >= 0; i--)
    {
        if (s.empty())
            ans.push_back(-1);

        else if (s.size() > 0 && a[i] < s.top())
        {
            ans.push_back(s.top());
        }
        else if (s.size() > 0 && a[i] > s.top())
        {
            while (s.size() > 0 && a[i] > s.top())
            {
                s.pop();
            }

            if(s.empty()) {
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
        }
        s.push(a[i]);
    }

    reverse(ans.begin(), ans.end());
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