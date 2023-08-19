#include <bits/stdc++.h>
using namespace std;

int recur(string s, int idx1, string t, int idx2)
{
    if (idx1 < 0 || idx2 < 0)
    {
        return 0;
    }
    if (s[idx1] == t[idx2])
    {
        return 1 + recur(s, idx1 - 1, t, idx2 - 1);
    }
    return max(recur(s, idx1 - 1, t, idx2), recur(s, idx1, t, idx2 - 1));
}
int memo(string s, int idx1, string t, int idx2, vector<vector<int>> &dp)
{
    if (idx1 < 0 || idx2 < 0)
    {
        return 0;
    }
    if (dp[idx1][idx2] != -1)
    {
        return dp[idx1][idx2];
    }
    if (s[idx1] == t[idx2])
    {
        return dp[idx1][idx2] = 1 + recur(s, idx1 - 1, t, idx2 - 1);
    }
    return dp[idx1][idx2] = max(recur(s, idx1 - 1, t, idx2), recur(s, idx1, t, idx2 - 1));
}
int tab(string s, int idx1, string t, int idx2)
{
    vector<vector<int>> dp(idx1 + 1, vector<int>(idx2 + 1, -1));
    for (int j = 0; j <= idx1; j++)
    {
        dp[j][0] = 0;
    }
    for (int j = 0; j <= idx2; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= idx1; i++)
    {
        for (int j = 1; j <= idx2; j++)
        {
            if(s[i]==t[j]) {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
        }
    }
    return dp[idx1][idx2];
}
int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int r = recur(text1, n, text2, m);
    int mr = memo(text1, n, text2, m, dp);
    int t = tab(text1,n,text2,m);
    cout << t << "\n";
}

//  function(s,2,t,5) --->  LCS between 0 to 2 of string s and in between 0 to 5 of string t