#include <bits/stdc++.h>
using namespace std;

int memo(vector<int> &arr, vector<vector<int>> &dp, int tgt, int ind)
{
    if (tgt == 0)
        return 1;
    if (ind == 0)
        return (arr[ind] == tgt);

    if (dp[ind][tgt] != -1)
        return dp[ind][tgt];

    int pick = 0;
    if (tgt >= arr[ind])
    {
        pick = memo(arr, dp, tgt - arr[ind], ind - 1);
    }
    int not_pick = memo(arr, dp, tgt, ind - 1);

    return dp[ind][tgt] = (pick + not_pick);
}

int tab(vector<int> &arr, int ind, int k)
{
    vector<vector<int>> dp(ind + 1, vector<int>(k + 1, 0));

    // if target i.e. k==0
    for (int i = 0; i < arr.size(); i++)
    {
        dp[i][0] = 1;
    }
    // if index == 0
    if (k >= arr[ind])
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int pick = 0;
            if (j >= arr[i])
                pick = dp[i - 1][j - arr[i]];
            int not_pick = dp[i - 1][j];

            dp[i][j] = (pick + not_pick);
        }
    }
    return dp[arr.size()-1][k];
}

int main()
{
    vector<int> arr = {5, 2, 6, 4};
    int n = arr.size();

    int sum = 0;
    int d = 3;
    for (int i : arr)
        sum += i;

    int k = (sum - d) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    int m = memo(arr, dp, k, n - 1);
    int t = tab(arr,n-1,k);

    cout << t << "\n";
}