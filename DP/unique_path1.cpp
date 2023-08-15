#include <bits/stdc++.h>
using namespace std;

int recur(int row, int col)
{
    if (row == 0 && col == 0)
    {
        return 1;
    }
    if (row < 0 || col < 0)
    {
        return 0;
    }

    int path1 = recur(row - 1, col);
    int path2 = recur(row, col - 1);

    return path1 + path2;
}

// for memoization check which params are changing and then form the dp data structure accordingly
int memo(int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
    {
        return 1;
    }
    if (row < 0 || col < 0)
    {
        return 0;
    }

    if (dp[row][col] != -1)
        return dp[row][col];

    int path1 = recur(row - 1, col);
    int path2 = recur(row, col - 1);

    return dp[row][col] = path1 + path2;
}
int tab(int row, int col)
{
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            int p1 = 0, p2 = 0;
            
            if (i > 0)
            {
                p1 = dp[i - 1][j];
            }
            if (j > 0)
            {
                p2 = dp[i][j - 1];
            }

            dp[i][j] = (p1 + p2);
        }
    }
    return dp[row - 1][col - 1];
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int r = recur(n - 1, m - 1);
    int mr = memo(n - 1, m - 1, dp);
    int t = tab(n, m);

    cout << t << "\n";
}