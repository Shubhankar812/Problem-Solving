#include <bits/stdc++.h>
using namespace std;

int lcs(string &s1, int ind1, string &s2, int ind2, vector<vector<int>> &dp)
{

    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }
    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    if (s1[ind1] == s2[ind2])
    {
        return dp[ind1][ind2] = 1 + lcs(s1, ind1 - 1, s2, ind2 - 1, dp);
    }
    return dp[ind1][ind2] = max(lcs(s1, ind1 - 1, s2, ind2, dp), lcs(s1, ind1, s2, ind2 - 1, dp));
}
int main()
{
    string s = "abcd";
    string t = "anc";
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    
    int l = lcs(s,n-1,t,m-1,dp);

    cout<<(n+m-2*l)<<endl;
}