#include <bits/stdc++.h>
using namespace std;

int recur(vector<int> &coins, int amt, int ind)
{

    if (ind == 0)
    {
        if (amt % coins[ind] == 0)
        {
            return 1;
        }
    }
    int not_pick = recur(coins, amt, ind - 1);
    int pick = 0;
    if (amt >= coins[ind])
    {
        pick = recur(coins, amt - coins[ind], ind);
        // here we are not trying to count the no. of coins that make up the required amount instead we are counting no. of ways
        // with which we can generate the required amount with the avaliable coins.
    }
    return pick + not_pick;
}
int memo(vector<int> &coins, vector<vector<int>> &dp, int amt, int ind)
{

    if (ind == 0)
    {
        if (amt % coins[0] == 0)
        {
            return 1;
        }
    }
    if (dp[ind][amt] != -1)
    {
        return dp[ind][amt];
    }
    int not_pick = memo(coins, dp, amt, ind - 1);
    int pick = 0;
    if (amt >= coins[ind])
    {
        pick = memo(coins, dp, amt - coins[ind], ind);
    }
    return dp[ind][amt] = pick + not_pick;
}
int tab(vector<int> &coins, int amt)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));

    for (int i = 0; i <= amt; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amt; j++)
        {
            int not_pick = dp[i - 1][j];
            int pick = 0;
            if (j >= coins[i])
            {
                pick = dp[i][j - coins[i]];
            }

            dp[i][j] = pick + not_pick;
        }
    }
    return dp[n - 1][amt];
}

int main()
{
    vector<int> arr = {1, 2, 5};
    int n = arr.size();
    int amt = 5;
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, -1));

    int r = recur(arr, amt, n - 1);
    int m = memo(arr, dp, amt, n - 1);
    int t = tab(arr, amt);

    cout << m << "\n";
}

// f(ind,T) --> min. coins required to form target T from index 0 to ind