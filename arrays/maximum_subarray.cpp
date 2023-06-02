#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum=0, mx = INT_MIN;

        for(int i=0;i<n;i++) {
            sum += nums[i];

            mx = max(mx,sum);

            if(sum < 0) {
                sum=0;
            }
        }
        return mx;
    }
};

int main()
{
    Solution s;
    vector<int> A = {2,3,-2,4};
    cout<<s.maxSubArray(A)<<endl;
}