#include <bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int> &nums)
{
    int sum = 0, leftSum = 0;
    for (int x : nums)
    {
        sum += x;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (leftSum == sum - leftSum - nums[i])
        {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;
}
int main()
{
    vector<int> nums = {2, 1, -1};
    
    int res = pivotIndex(nums);

    cout<<res<<endl;

}