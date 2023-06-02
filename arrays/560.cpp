#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        int count = 0;

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            if (prefix[i] == k)
            {
                count += 1;
            }

            if (map.find(prefix[i] - k) != map.end())
            {
                count += map[prefix[i] - k];
            }
            
            map[prefix[i]]++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout<<s.subarraySum(nums,k)<<endl;
}