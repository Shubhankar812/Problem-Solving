#include <bits/stdc++.h>
using namespace std;

bool memo(vector<int> &arr, vector<vector<int>> &dp, int tgt, int ind)
{
    if(tgt==0)	return true;
	if(ind==0)	return (arr[ind] == tgt);

	if(dp[ind][tgt] != -1) 	return dp[ind][tgt];

	int pick = 0;
	if(tgt >= arr[ind]) {
		pick = memo(arr,dp,tgt-arr[ind],ind-1);
	}
	int not_pick = memo(arr,dp,tgt,ind-1);

	return dp[ind][tgt] = (pick || not_pick);
}
int main()
{
    int n = 6;
    vector<int> arr = {3, 1, 1, 2, 2, 1};

    int sum = 0;
    for (auto it : arr)
        sum += it;

    if (sum & 1)
        cout << "Not Possible"
             << "\n";

    int k = sum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    bool m = memo(arr,dp,k,n-1);

    cout<<m<<"\n";
}