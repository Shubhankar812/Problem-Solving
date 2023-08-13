#include <bits/stdc++.h>
using namespace std;
int recur(int n, vector<int> &arr)
{
    if (n == 0)
    {
        return 0;
    }
    int c1 = recur(n - 1, arr) + abs(arr[n] - arr[n - 1]);
    int c2 = 1e9;
    if (n > 1)
    {
        c2 = recur(n - 2, arr) + abs(arr[n] - arr[n - 2]);
    }
    return min(c1, c2);
}
int memo(int i, vector<int> &arr, vector<int> &dp)
{
    if (i == 0)
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];

    int c1 = memo(i - 1, arr, dp) + abs(arr[i] - arr[i - 1]);
    int c2 = 1e9;
    if (i > 1)
    {
        c2 = memo(i - 2, arr, dp) + abs(arr[i] - arr[i - 2]);
    }
    return dp[i] = min(c1, c2);
}
int tab(int ind, vector<int> &arr)
{
    vector<int> dp(ind , -1);

    dp[0] = 0;

    for (int i = 1; i <= arr.size(); i++)
    {
        int c1 = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int c2 = 1e9;
        if (i > 1)
        {
            c2 = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        }
        dp[i] = min(c1, c2);
    }
    return dp[arr.size()-1];
}
int main()
{
    vector<int> a = {10, 20, 30, 10};
    int idx = a.size() - 1;

    int r = recur(idx, a);
    vector<int> dp(idx + 1, -1);
    int m = memo(idx, a, dp);
     int t = tab(idx, a);
    // cout << m << "\n";
    // cout << r << "\n";
    cout << t << "\n";
}