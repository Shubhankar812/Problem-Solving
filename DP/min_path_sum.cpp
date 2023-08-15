#include <bits/stdc++.h>
using namespace std;

int recur(int r, int c, vector<vector<int>> &grid)
{
    if (r == 0 && c == 0)
    {
        return grid[r][c];
    }
    if (r < 0 || c < 0)
    {
        return 1e9;
    }
    int p1 = 0, p2 = 0;

    p1 = grid[r][c] + recur(r - 1, c, grid);
    p2 = grid[r][c] + recur(r, c - 1, grid);

    return min(p1, p2);
}

int memo(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (r == 0 && c == 0)
    {
        return grid[r][c];
    }
    if (r < 0 || c < 0)
    {
        return 1e9;
    }
    if (dp[r][c] != -1)
        return dp[r][c];
    int p1 = 0, p2 = 0;

    p1 = grid[r][c] + recur(r - 1, c, grid);
    p2 = grid[r][c] + recur(r, c - 1, grid);

    return dp[r][c] = min(p1, p2);
}

int tab(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(r + 1, vector<int>(c + 1, -1));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }
            int p1 = 0;
            int p2 = 0;

            if (i > 0)
            {
                p1 = dp[i - 1][j] + grid[i][j];
            }
            else
            {
                p1 += 1e9;
            }
            if (j > 0)
            {
                p2 = dp[i][j - 1] + grid[i][j];
            }
            else
            {
                p2 += 1e9;
            }
            dp[i][j] = min(p1, p2);
        }
    }
    return dp[r - 1][c - 1];
}
int main()
{
    vector<vector<int>> matrix = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int r = recur(n - 1, m - 1, matrix);
    int mr = memo(n - 1, m - 1, matrix, dp);
    int t = tab(n - 1, m - 1, matrix);

    cout << t << "\n";
}