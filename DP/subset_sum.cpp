#include <bits/stdc++.h>
using namespace std;

bool recur(vector<int> &arr, int ind, int k)
{
    if (ind == 0)
    {
        if (arr[ind] == k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (k == 0)
    {
        return true;
    }
    int pick = 0;
    if (ind > 0)
    {
        pick = recur(arr, ind - 1, k - arr[ind]);
    }
    int not_pick = recur(arr, ind - 1, k);

    return (pick || not_pick);
}
bool memo(vector<int> &arr, vector<vector<bool>> &dp, int ind, int k)
{
    if (ind == 0)
    {
        if (arr[ind] == k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (k == 0)
    {
        return true;
    }

    if (dp[ind][k] != false)
    {
        return dp[ind][k];
    }
    bool pick = 0;
    if (ind > 0)
    {
        pick = memo(arr, dp, ind - 1, k - arr[ind]);
    }
    bool not_pick = memo(arr, dp, ind - 1, k);

    return dp[ind][k] = (pick || not_pick);
}
bool tab(vector<int> &arr, int ind, int k)
{
    vector<vector<bool>> dp(10001, vector<bool>(10001, false));

    for (int i = 0; i < arr.size(); i++)
    {
        dp[i][0] = 1;
    }
   if(arr[ind] <= k) {
      dp[0][arr[0]] = true;
   }

    for (int i = 1; i < ind; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool pick = false;
            if (j >= arr[i])
            {
                pick = dp[i - 1][j - arr[i]];
            }

            bool not_pick = dp[i - 1][j];

            dp[i][j] = (pick || not_pick);
        }
    }
    return dp[ind-1][k];
}
int main()
{
    int n = 6;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    vector<vector<bool>> dp(10001, vector<bool>(10001, false));

    bool r = recur(arr, n - 1, sum);
    bool m = memo(arr, dp, n - 1, sum);
    bool t = tab(arr,n-1,sum);

    if (t)
        cout << "True"
             << "\n";
    else
        cout << "False"
             << "\n";
}