#include <bits/stdc++.h>
using namespace std;

int recur(int ind) {
    if(ind<=1) {
        return ind;
    }
    return recur(ind-1)+recur(ind-2);
}
int memo(int ind,vector<int> &dp) {
    if(ind<=1) {
        return ind;
    }
    if(dp[ind] != -1) {
        return dp[ind];
    }
    return dp[ind] = memo(ind-1,dp)+memo(ind-2,dp);
}
int tab(int ind) {
    vector<int> dp(ind+1,-1);
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=ind;i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[ind];
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);

    int r = recur(n);
    int m = memo(n,dp);
    int t = tab(n);
    cout<<t<<"\n";
}