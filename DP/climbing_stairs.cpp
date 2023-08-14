#include <bits/stdc++.h>
using namespace std;

int recur(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int left = recur(n - 1);
    int right = recur(n - 2);

    return left + right;
}
int memo(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int left = memo(n - 1, dp);
    int right = memo(n - 2, dp);

    return dp[n] = left + right;
}
int tab(int n)
{
    vector<int> dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++) {
        int left = dp[i-1];
        int right = dp[i-2];

        dp[i] = left+right;
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