#include <bits/stdc++.h>
using namespace std;
int recur(int ind, int k, vector<int> arr)
{
    if (ind == 0)
        return 0;
    int ans = 1e9;
    for (int j = 1; j <= k; j++)
    {
        int jump = 0;
        if (ind - j >= 0)
        {
            jump = recur(ind - j, k, arr) + abs(arr[ind] - arr[ind - j]);

            ans = min(ans, jump);
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
        return dp[ind];

    for (int j = 1; j <= k; j++)
    {
        int jump = 0;
        if (ind - j >= 0)
        {
            jump = memo(ind - j, k, arr, dp) + abs(arr[ind] - arr[ind - j]);

            ans = min(ans, jump);
        }
    }
    return dp[ind] = ans;
}
int tab(int k, vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n , -1);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int res = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(arr[i] - arr[i - j]);

                res = min(res, jump);
            }
        }
        dp[i] = res;
    }
    return dp[n - 1];
}
int main()
{
    vector<int> arr = {10, 40, 30, 10};
    int n = 4, k = 2;

    vector<int> dp(n + 1, -1);

    // int r = recur(n - 1, k, arr);
    // int m = memo(n - 1, k, arr, dp);
    int t = tab(k, arr);

    cout << t << "\n";
}