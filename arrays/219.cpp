#include <bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (mpp.count(nums[i]))
        {
            if (abs(i - mpp[nums[i]]) <= k)
            {
                return true;
            }
        }
        mpp[nums[i]] = i;
    }
    return false;
}
int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    bool ans = containsNearbyDuplicate(nums,k);
    if(ans){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}