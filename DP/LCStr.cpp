#include <bits/stdc++.h>
using namespace std;

int tab(string S1, string S2, int n, int m)
{
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                int val = 1 + dp[i - 1][j - 1];
                dp[i][j] = val;
                ans = max(ans, val);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}
int main()
{
    string s = "adadac";
    string t = "adac";

    int n = s.length();
    int m = t.length();

    int tb = tab(s, t, n, m);

    cout << tb << "\n";
}