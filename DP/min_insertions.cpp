#include <bits/stdc++.h>
using namespace std;

int solve(string &s, int n, string &t, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
        string s = "mbadm";
        int n = s.length();
        string t = s;
        int m = t.length();
        reverse(s.begin(),s.end());

        int l = solve(s,n,t,m);

        cout<<n-l<<"\n";
}

// 1. Keep the longest palindromic subsequence(LPS) constant 
// 2. The elements which are not the part of LPS have to be repeated for the string to be a palindrome.  