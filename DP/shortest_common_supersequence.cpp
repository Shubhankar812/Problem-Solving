#include <bits/stdc++.h>
using namespace std;

 int lcs(string text1, string text2) {
        int t1 = text1.length();
        int t2 = text2.length();
        vector<vector<int>> dp(t1+1,vector<int>(t2+1,-1));
        
        // base case 
        for(int i=0;i<=t1;i++) {
            dp[i][0] = 0;
        }
        for(int i=0;i<=t2;i++) {
            dp[0][i] = 0;
        }

        for(int i=1;i<=t1;i++) {
            for(int j=1;j<=t2;j++) {

                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }

        }
        return dp[t1][t2];
    }
int main()
{
    // length of shortest common supersequence = s1.length() + s2.length() - LCS(s1,s2);
    string s = "abcde", t = "ace";
    int n = s.length();
    int m = t.length();

    int r = n+m-lcs(s,t);

    cout<<r<<"\n";
}