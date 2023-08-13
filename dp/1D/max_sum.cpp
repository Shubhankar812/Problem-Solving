#include <bits/stdc++.h>
using namespace std;
int recur(int ind, vector<int> &arr)
{
    if (ind == 0)
    {
        return arr[ind];
    }
    int pick = 0;
    if (ind > 1)
    {
        pick = recur(ind - 2, arr) + arr[ind];
    }
    int not_pick = recur(ind - 1, arr);

    return max(pick, not_pick);
}

int memo(int ind, vector<int> &arr, vector<int> &dp)
{

    if (ind == 0)
    {
        return arr[ind];
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int pick = 0;
    if (ind > 1)
    {
        pick = recur(ind - 2, arr) + arr[ind];
    }
    int not_pick = recur(ind - 1, arr);

    return dp[ind] = max(pick, not_pick);
}
int tab(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    
    dp[0] = arr[0];

    for(int i=1;i<n;i++) {
       int pick = 0;
       int not_pick = dp[i-1];
       if(i>1) {
        pick = dp[i-2] + arr[i]; 
       } 
       dp[i] = max(pick,not_pick);
    }
    return dp[n-1];
}
int main()
{
    int n = 4;

    vector<int> a = {2, 1, 4, 9};
    vector<int> dp(n + 1, -1);

    int r = recur(n - 1, a);
    int m = memo(n - 1, a, dp);
    int t = tab(a);
    cout << t << "\n";
}