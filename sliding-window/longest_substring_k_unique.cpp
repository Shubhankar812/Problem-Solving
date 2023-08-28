#include <bits/stdc++.h>
using namespace std;

int solve(string &s, int k)
{
    int n = s.length();
    int i = 0, j = 0;
    int mx = -1e9;

    unordered_map<char, int> mp;
    mp.clear();

    while (j < n)
    {
        mp[s[j]]++;

        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;

                if(mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;
}
int main()
{
    string s = "aabacbebebe";
    int k = 3;

    int r = solve(s, k);

    cout << r << "\n";
}