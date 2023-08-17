#include <bits/stdc++.h>
using namespace std;

int recur(vector<int> &coins, int amt, int ind)
{

    if (ind == 0)
    {
        if (amt % coins[ind] == 0)
        {
            return amt / coins[ind];
        }
        else
        {
            return 1e9;
        }
    }
    int not_pick = recur(coins, amt, ind - 1);
    int pick = 1e9;
    if (amt >= coins[ind])
    {
        pick = 1 + recur(coins, amt - coins[ind], ind);
    }
    return min(pick, not_pick);
}
int memo(vector<int> &coins, vector<vector<int>> &dp, int amt, int ind)
{

    if (ind == 0)
    {
        if (amt % coins[0] == 0)
        {
            return amt / coins[ind];
        }
        else
        {
            return 1e9;
        }
    }
    if (dp[ind][amt] != -1)
    {
        return dp[ind][amt];
    }
    int not_pick = memo(coins, dp, amt, ind - 1);
    int pick = 1e9;
    if (amt >= coins[ind])
    {
        pick = 1 + memo(coins, dp, amt - coins[ind], ind);
    }
    return dp[ind][amt] = min(pick, not_pick);
}
int tab(vector<int> &coins, int amt)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));

    for (int i = 0; i <= amt; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[0][i] = i / coins[0];
        }
        else
        {
            dp[0][i] = 1e9;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amt; j++)
        {
             int not_pick = dp[i - 1][j];
            int pick = 1e9;
            if (j >= coins[i])
            {
                pick = 1 + dp[i][j - coins[i]];
            }
           

            dp[i][j] = min(pick, not_pick);
        }
    }
    return dp[n - 1][amt];
}

int main()
{
    vector<int> arr = {1, 2, 5};
    int n = arr.size();
    int amt = 11;
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, -1));

    int r = recur(arr, amt, n - 1);
    int m = memo(arr, dp, amt, n - 1);
    int t = tab(arr, amt);

    cout << t << "\n";
}

// f(ind,T) --> min. coins required to form target T from index 0 to ind