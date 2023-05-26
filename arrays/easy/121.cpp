#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int buy = 0, sell = 1;
    int maxProfit = 0;

    while (sell < prices.size())
    {
        if (prices[sell] > prices[buy])
        {
            int profit = prices[sell] - prices[buy];
            maxProfit = max(profit, maxProfit);
        }
        else
        {
            buy = sell;
        }
        sell++;
    }
    return maxProfit;
}
int main()
{
    vector<int> arr = {7,1,5,3,6,4};
    int res = maxProfit(arr);

    cout<<res<<"\n";
}