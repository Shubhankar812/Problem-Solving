#include <bits/stdc++.h>
using namespace std;

int recur(vector<int> wt, vector<int> val, int ind, int capacity)
{
    if (ind == 0)
    {
        if (capacity >= wt[0])
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }
    int pick = 0;
    if (wt[ind] <= capacity)
    {
        pick = recur(wt, val, ind - 1, capacity - wt[ind]) + val[ind];
    }

    int not_pick = recur(wt, val, ind - 1, capacity);

    return max(pick, not_pick);
}
int memo(vector<vector<int>> dp, vector<int> wt, vector<int> val, int ind, int capacity)
{
    if (ind == 0)
    {
        if (capacity >= wt[0])
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[ind][capacity] != -1)
    {
        return dp[ind][capacity];
    }
    int pick = 0;
    if (wt[ind] <= capacity)
    {
        pick = memo(dp, wt, val, ind - 1, capacity - wt[ind]) + val[ind];
    }

    int not_pick = memo(dp, wt, val, ind - 1, capacity);

    return dp[ind][capacity] = max(pick, not_pick);
}

int tab(vector<int> wt, vector<int> val, int ind, int capacity)
{
    vector<vector<int>> dp(ind + 1, vector<int>(capacity + 1, 0));

    for (int i = wt[0]; i <= capacity; i++)
    {
        dp[0][i] = val[0];
    }

    for (int i = 1; i <= ind; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            int pick = -1e9;
            if (j >= wt[i])
            {
                pick = dp[i - 1][j - wt[i]] + val[i];
            }
            int not_pick = dp[i - 1][j];

            dp[i][j] = max(pick, not_pick);
        }
    }
    return dp[ind - 1][capacity];
}
int main()
{
    int n = 4;
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int cap = 5;

    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));

    int r = recur(wt, val, n - 1, cap);
    int m = memo(dp, wt, val, n - 1, cap);
    int t = tab(wt, val, n - 1, cap);

    cout << t << "\n";
}

// f(ind,W) --> max. value of items from index 0 to 'ind' with the knapsack capacity of W