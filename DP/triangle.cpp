#include <bits/stdc++.h>
using namespace std;

int recur(vector<vector<int>> &grid, int r, int c)
{
    // base case
    if (r == grid.size() - 1)
    {
        return grid[grid.size() - 1][c];
    }
    int path1 = recur(grid, r + 1, c) + grid[r][c];     // going down
    int path2 = recur(grid, r + 1, c + 1) + grid[r][c]; // going along the diagonal

    return min(path1, path2);
}

int memo(vector<vector<int>> &grid, vector<vector<int>> &dp, int r, int c)
{
    // base case
    if (r == grid.size() - 1)
    {
        return grid[grid.size() - 1][c];
    }
    if (dp[r][c] != -1)
    {
        return dp[r][c];
    }
    int path1 = memo(grid, dp, r + 1, c) + grid[r][c];     // going down
    int path2 = memo(grid, dp, r + 1, c + 1) + grid[r][c]; // going along the diagonal

    return dp[r][c] = min(path1, path2);
}
int tab(vector<vector<int>> &grid, int r, int c)
{
    int n = grid.size();
    int m = grid[n - 1].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = grid[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int p1 = grid[i][j] + dp[i+1][j];
            int p2 = grid[i][j] + dp[i+1][j+1];

            dp[i][j] = min(p1,p2);
        }
    }
    return dp[0][0];
}
int main()
{
    vector<vector<int>> grid = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int n = grid.size();
    int m = grid[n - 1].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int r = recur(grid, 0, 0);
    int mr = memo(grid, dp, 0, 0);
    int t = tab(grid, n - 1, m - 1);

    cout << t << "\n";
}
// You have 2 options, you can either go down or go along a diagonal.