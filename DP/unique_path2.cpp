#include <bits/stdc++.h>
using namespace std;

int memo(int r, int c, vector<vector<int>> &maze, vector<vector<int>> &dp)
{

    if ((r >= 0 && c >= 0) && maze[r][c] == -1)
    {
        return 0;
    }
    if (r == 0 && c == 0)
        return 1;
    if (r < 0 || c < 0)
        return 0;

    if (dp[r][c] != -1)
    {
        return dp[r][c];
    }
    int p1 = 0, p2 = 0;
    p1 = memo(r - 1, c, maze, dp);
    p2 = memo(r, c - 1, maze, dp);

    return dp[r][c] = (p1 + p2);
}
int tab(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(r + 1, vector<int>(c + 1, -1));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            else
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                int p1 = 0, p2 = 0;
                if (i > 0)
                    p1 = dp[i - 1][j];
                if (j > 0)
                    p2 = dp[i][j - 1];

                dp[i][j] = p1 + p2;
            }
        }
    }
    return dp[r - 1][c - 1];
}
int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int mr = memo(n - 1, m - 1, grid, dp);
    int t = tab(n, m, grid);

    cout << t << "\n";
}