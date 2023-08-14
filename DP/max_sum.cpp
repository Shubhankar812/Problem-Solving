#include <bits/stdc++.h>
using namespace std;

int recur(int ind, vector<int> &arr)
{
    // base case
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    int pick = arr[ind] + recur(ind - 2, arr);
    int not_pick = recur(ind - 1, arr);

    return max(pick, not_pick);
}
int memo(int n, vector<int> &arr, vector<int> &dp)
{
    // base case
    if (n == 0)
        return arr[n];
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int pick = arr[n] + memo(n - 2, arr, dp);
    int not_pick = memo(n - 1, arr, dp);

    return dp[n] = max(pick, not_pick);
}

int tab(int n, vector<int> &arr)
{
    vector<int> dp(n + 1, -1);
    dp[0] = arr[0];

    for (int i = 1; i <= n; i++)
    {
        int pick = -1e9;
        if (i > 1)
        {
            pick = arr[i] + dp[i - 2];
        }
        int not_pick = dp[i - 1];

        dp[i] = max(pick, not_pick);
    }
    return dp[n];
}
int main()
{
    int n = 4;
    vector<int> arr = {2, 1, 4, 9};
    vector<int> dp(n + 1, -1);

    int r = recur(n - 1, arr);
    int m = memo(n, arr, dp);
    int t = tab(n - 1, arr);

    cout << t << "\n";
}