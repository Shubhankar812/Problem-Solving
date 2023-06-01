#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int k, int n)
{
    int i = 0, j = 0;
    int mx = INT_MIN;
    int sum = 0;

    while (j < n)
    {
        sum += arr[j];

        if (sum == k)
        {
            mx = max(mx, j - i + 1);
            
        }
        else if (sum > k)
        {
            // remove the iteration for arr[i]
           while(sum > k) {
            sum-=arr[i];
            i++;
           }
        }
        j++;
    }
    return mx;
}
int main()
{
    vector<int> nums = {4, 1, 1, 1, 2, 3, 5};
    int k = 5;
    int n = 7;

    cout << solve(nums, k, n) << endl;
    return 0;
}