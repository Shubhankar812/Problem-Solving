#include <bits/stdc++.h>
using namespace std;

int recur(int ind, int k, vector<int> &arr)
{
    if (ind == 0)
        return 0;

    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {

        if (ind - i >= 0)
        {
            int c = recur(ind - i, k, arr) + abs(arr[i] - arr[i - k]);
            ans = min(ans, c);
        }
    }
    return ans;
}

int memo(int ind, int k, vector<int> &arr, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    int ans = 1e9;
    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    for (int i = 1; i <= k; i++)
    {

        if (ind - i >= 0)
        {
            int c = recur(ind - i, k, arr) + abs(arr[i] - arr[i - k]);
            ans = min(ans, c);
        }
    }
    return dp[ind] = ans;
}

int tab(int ind, int k, vector<int> &arr)
{
    vector<int> dp(ind + 1, 0);
    dp[0] = 0;

    for (int i = 1; i < ind; i++)
    {
        int ans = 1e9;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int c = dp[i - j] + abs(arr[i] - arr[i - j]);
                ans = min(ans, c);
            }
        }
        dp[i] = ans;
    }
    return dp[ind-1];
}

int main()
{
    int n = 4;
    int k = 2;
    vector<int> arr = {10, 40, 30, 10};
    vector<int> dp(n + 1, -1);

    int r = recur(n, k, arr);
    int m = memo(n, k, arr, dp);
    int t = tab(n, k, arr);

    cout << t << endl;
}