#include <bits/stdc++.h>
using namespace std;

int memo(vector<int> arr, vector<vector<int>> &dp, int k, int ind)
{
    if (ind == 0)
    {
        if (k == 0 || arr[0] == k)
            return 1;
        if (k == 0 && arr[0] == k)
            return 2;
        else
            return 0;
    }
    if (dp[ind][k] != -1)
        return dp[ind][k];
    int pick = 0;
    if (k >= arr[ind])
        pick = memo(arr, dp, k - arr[ind], ind - 1);

    int not_pick = memo(arr, dp, k, ind - 1);

    return dp[ind][k] = (pick + not_pick);
}
int tab(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= k)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int not_pick = dp[i - 1][j];
            int pick = 0;
            if (j >= arr[i])
                pick = dp[i - 1][j - arr[i]];
            

            dp[i][j] = (pick + not_pick);
        }
    }
    return dp[n - 1][k];
}
int main()
{
    int n = 5;
    vector<int> arr(n, 1);
    int tgt = 3;
    int sum = 0;

    for (auto it : arr)
        sum += it;

    int k = (sum - tgt) / 2;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    int m = memo(arr, dp, k, n - 1);
    int t = tab(arr, k);
    cout << t << "\n";
}