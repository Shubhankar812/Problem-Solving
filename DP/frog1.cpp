#include <bits/stdc++.h>
using namespace std;

int recur(int ind, vector<int> &arr)
{
    if (ind == 0)
    {
        return 0;
    }
    int c1 = recur(ind - 1, arr) + abs(arr[ind] - arr[ind - 1]);
    int c2 = 1e9;
    if (ind > 1)
    {
        c2 = recur(ind - 2, arr) + abs(arr[ind] - arr[ind - 2]);
    }
    return min(c1, c2);
}
int memo(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int c1 = memo(ind - 1, arr, dp) + abs(arr[ind] - arr[ind - 1]);

    int c2 = 1e9;

    if (ind > 1)
    {
        c2 = memo(ind - 2, arr, dp) + abs(arr[ind] - arr[ind - 2]);
    }

    return dp[ind] = min(c1, c2);
}
int tab(int n, vector<int> &arr)
{
    vector<int> dp(n + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int c1 = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int c2 = 1e9;
        if (i > 1)
        {
            c2 = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        }
        dp[i] = min(c1, c2);
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr = {10, 20, 30, 10};
    vector<int> dp(n + 1, -1);

    int r = recur(n - 1, arr);
    int m = memo(n - 1, arr, dp);
    int t = tab(n - 1, arr);

    cout << t << "\n";
}