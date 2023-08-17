#include <bits/stdc++.h>
using namespace std;

int recur(vector<int> arr, int ind, int k)
{
    if (k == 0)
        return 1;
    if (ind == 0)
        return (arr[ind] == k);

    int pick = 0;
    if (arr[ind] <= k)
        pick = recur(arr, ind - 1, k - arr[ind]);
    int notPick = recur(arr, ind - 1, k);

    return (pick + notPick);
}
int memo(vector<int> arr, vector<vector<int>> &dp, int ind, int k)
{
    if (k == 0)
        return 1;
    if (ind == 0)
        return (arr[ind] == k);

    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }
    int pick = 0;
    if (arr[ind] <= k)
        pick = recur(arr, ind - 1, k - arr[ind]);
    int notPick = recur(arr, ind - 1, k);

    return dp[ind][k] = (pick + notPick);
}
int tab(vector<int> &arr, int ind, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= k)
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int not_pick = dp[i - 1][j];
            int pick = 0;
            if (j >= arr[i]){
                pick = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = pick + not_pick;
        }
    }
    return dp[n - 1][k];
}
int main()
{
    vector<int> arr = {1, 1, 4, 5};
    int n = arr.size();
    int k = 5;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    int r = recur(arr, n - 1, k);
    int m = memo(arr, dp, n - 1, k);
    int t = tab(arr, n - 1, k);

    cout << t << "\n";
}