#include <bits/stdc++.h>
using namespace std;

int solve(string &s)
{
    unordered_map<char, int> mp;
    int n = s.length();
    int left = 0;
    int right = 0;
    int ans = 0;

    while (right < n)
    {
        char r = s[right];
        mp[r]++;

        while (mp[r] > 1)
        {
            char l = s[left];
            mp[l]--;
            left++;
        }

        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;

    int r = solve(s);

    cout << r << "\n";
}