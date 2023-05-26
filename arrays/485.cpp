#include <bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int ans = INT_MIN;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count += 1;
        }
        else
        {
            count = 0;
        }
        ans = max(ans, count);
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int res = findMaxConsecutiveOnes(nums);
    cout<<res<<endl;
}