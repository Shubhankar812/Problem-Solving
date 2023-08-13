#include <bits/stdc++.h>
using namespace std;

int recur(int idx)
{
    if (idx <= 1)
    {
        return 1;
    }
    int left = recur(idx - 1);
    int right = recur(idx - 2);

    return left + right;
}
int memo(int idx, vector<int> &dp)
{
    if (idx <= 1)
    {
        return 1;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    int left = memo(idx - 1, dp);
    int right = memo(idx - 2, dp);

    return dp[idx] = left + right;
}
int tab(int n)
{
    vector<int>dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);

    int r = recur(n);
    int m = memo(n, dp);
    int t = tab(n);
    cout << t << "\n";
}