#include <bits/stdc++.h>
using namespace std;

int memo(vector<vector<int>> &mat, vector<vector<int>> &dp, int r, int c)
{
    int m = mat[0].size();
    if (c < 0 || c > m - 1)
    {
        return 1e9;
    }
    if (r == 0)
    {
        return mat[r][c];
    }

    if (dp[r][c] != -1)
    {
        return dp[r][c];
    }

    int left = mat[r][c] + memo(mat, dp, r - 1, c - 1);
    int right = mat[r][c] + memo(mat, dp, r - 1, c + 1);
    int down = mat[r][c] + memo(mat, dp, r - 1, c);

    return dp[r][c] = min(down, min(left, right));
}
int tab(vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = mat[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int left = mat[i][j];
            int right = mat[i][j];
            int down = mat[i][j];

            if (j > 0)
            {
                left += dp[i - 1][j - 1];
            }
            else
            {
                left += 1e9;
            }
            if (j < m - 1)
            {
                right += dp[i - 1][j + 1];
            }
            else
            {
                right += 1e9;
            }
            down = mat[i][j] + dp[i - 1][j];

            dp[i][j] = min(down, min(left, right));
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int mr = INT_MAX;

    for (int j = 0; j < m; j++)
    {
        mr = min(mr, memo(mat, dp, n - 1, j));
    }
    int t = tab(mat,dp);

    cout << t << endl;
}