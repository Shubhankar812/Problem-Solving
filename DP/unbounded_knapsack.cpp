#include <bits/stdc++.h>
using namespace std;

int memo(vector<int> &wt, vector<int> &val, vector<vector<int>> dp, int ind, int W)
{
    if (ind == 0)
    {
        return (W / wt[ind]) * val[ind];
    }
    int pick = 0;
    if (wt[ind] <= W)
    {
        pick = val[ind] + memo(wt, val, dp, ind, W - wt[ind]);
    }
    int not_pick = memo(wt, val, dp, ind - 1, W);

    return dp[ind][W] = max(pick, not_pick);
}
int tab(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = (i / wt[0]) * val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int not_pick = dp[i - 1][j];
            int pick = 0;
            if (j >= wt[i])
            {
                pick = dp[i][j - wt[i]] + val[i];
            }
            dp[i][j] = max(pick, not_pick);
        }
    }
    return dp[n-1][W];
}
int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    int n = wt.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    int m = memo(wt, val, dp, n - 1, W);
    int t = tab(wt,val,n-1,W);

    cout << t << "\n";
}

// f(ind,W) ---> return me the max profit from index 0 to ind, with capacity less than or equal to W